"""Run an existing ROM harness with PB:PC/M/X coverage; stores no instruction bytes.
usage: coverage_run.py ROM OUT.json TOOL [TOOL_ARGS ...]
The ROM is forwarded as the harness's first argument. Nonzero failures do not save coverage.
"""
import sys, os, json, hashlib, runpy, cpu65816 as cpu, romio

def main():
    path = sys.argv[1]
    out = sys.argv[2]
    tool = os.path.abspath(sys.argv[3])
    args = sys.argv[4:]
    rom = romio.load(path)
    tool_digest = hashlib.sha256(open(tool,'rb').read()).hexdigest()
    cpu_digest = hashlib.sha256(open(cpu.__file__,'rb').read()).hexdigest()
    coverage = set()
    cpu.set_coverage(coverage)
    sys.argv = [tool,path] + args
    try:
        runpy.run_path(tool,run_name='__main__')
    finally:
        cpu.set_coverage(None)
    report = {'rom_sha256':hashlib.sha256(rom).hexdigest(),'tool':os.path.basename(tool),
              'tool_sha256':tool_digest,'cpu_sha256':cpu_digest,
              'arguments':args,'schema':'entries = [24-bit PC, M, X]; hooks that bypass an instruction are excluded',
              'entries':[list(entry) for entry in sorted(coverage)]}
    with open(out,'w') as f:
        json.dump(report,f,separators=(',',':'))
        f.write('\n')
    print('coverage: %d PC/M/X states saved to %s' % (len(coverage),out))

if __name__ == '__main__':
    main()
