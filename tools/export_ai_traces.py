"""Dump real-ROM-verified traces of the AI bytecode machine, for testing a re-implementation of tools/ai_vm.py.
usage: export_ai_traces.py ROM STATE OUT ID N [--seed K] [--slot S]       ID: one monster id, a comma list of ids and LO-HI ranges, or "all" (0x00-0x53); with several ids OUT is a directory
(one file trace_<id>.json each), with one id OUT is the file. Each file is a JSON list of N steps {"in": ..., "out": ...}. The steps come from the same
randomised-world machinery as tools/monster_model.py (injected machine states included); only steps in which the model and the game agreed are written.
in:  slot (the monster's slot), rng (the random bytes in the order the script draws them, as many as were drawn), state (pc, stack = live return addresses,
     mem = the 16 stack words of the record, var[4], tgt, tgt2, saved), rec = {slot: {offset: value}} the object records of slots 0-5 before the step, only non-zero
     bytes (positions at +0x20/+0x22, jump height +0x45, active +0x00, status +0x190, level +0x181, HP +0x182, monster id +0x180, ...; the machine state is
     also present in the record at +0x144..+0x16F, +0x1AC, +0x1AD).
out: cmd (4 values, null where the op leaves the byte alone), yield (0 = the step ended on a yielding op), pc, stack, var, tgt, tgt2, saved, draws (random
     bytes consumed), effects (['set', slot, offset, value] | ['cast', spell, target slot] | ['flash'] | ['restart']), changed = {slot: {offset: value}} every byte of
     the records of slots 0-5 that the step changed (command bytes, state, fields written by ops).
The engine routines $C0:001B (cast) and $C0:003C (flash) are replaced by no-ops in the game run: their effects are the 'cast' / 'flash' entries."""
import sys, os, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, monster_model


def trace(rom, state, mid, n, seed=1, slot=3):
    s = monster_model.Session(rom, state, mid, seed, slot)
    out = []; bad = 0
    while len(out) < n:
        r = s.step()
        if 'error' in r:
            s.reset(); continue
        if not r['ok']:
            bad += 1; continue
        st = r['state_in']; m = r['model']
        out.append({'in': dict(slot=slot, rng=r['rng'], state=dict(pc=st['pc'], stack=st['stack'], mem=st['mem'], var=st['var'], tgt=st['tgt'], tgt2=st['tgt2'], saved=list(st['saved'])),
                               rec={str(k): {str(o): v for o, v in d.items()} for k, d in r['rec_in'].items() if d}),
                    'out': dict(cmd=[c if c is not None else None for c in m['cmd']], yield_=r['yielded'], pc=m['pc'], stack=m['stack'], var=m['var'], tgt=m['tgt'], tgt2=m['tgt2'],
                                saved=list(m['saved']), draws=m['draws'], effects=[list(e) for e in m['effects']],
                                changed={str(k): {str(o): v for o, v in d.items()} for k, d in r['model_changed'].items() if d})})
    return out, bad


def main():
    args = sys.argv[1:]; opts = {}
    for k in ('--seed', '--slot'):
        if k in args:
            i = args.index(k); opts[k] = int(args[i + 1]); del args[i:i + 2]
    rom = romio.load(args[0]); state, outp, ids, n = args[1], args[2], args[3], int(args[4])
    idl = monster_model.parse_ids(ids)
    if len(idl) > 1: os.makedirs(outp, exist_ok=True)
    for mid in idl:
        steps, bad = trace(rom, state, mid, n, opts.get('--seed', 1), opts.get('--slot', 3))
        for st in steps: st['out']['yield'] = st['out'].pop('yield_')
        path = os.path.join(outp, 'trace_%02X.json' % mid) if len(idl) > 1 else outp
        with open(path, 'w') as f: json.dump(steps, f, separators=(',', ':'))
        print('id %d: %d steps, %d disagreements skipped, %d bytes -> %s' % (mid, len(steps), bad, os.path.getsize(path), path)); sys.stdout.flush()


if __name__ == '__main__':
    main()
