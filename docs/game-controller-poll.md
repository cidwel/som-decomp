# Controller polling, reassignment and cold-reset transfer

`GameControllerPoll` reconstructs the native preserving wrapper C0939F (20 bytes), word validation/pressed-edge publication C093B9 (123), interface transition/first-player reassignment C0951C (52), the public long-return wrapper C08000 (4), and the hotkey transfer C093B3. The last catalogue range includes five live bytes (CLC/JSL) and one unreachable trailing RTS at C093B8. The call goes through C10010 and full cold boot to JML 7EAF0B; it cannot return to that RTS. Source accounting must distinguish the 204 live candidate bytes and that unreachable byte.

The model composes the frozen controller BIOS and mapping, actual controller assignment, palette/HUD publication and bounded native NMI. Automatic joypad busy intervals, serial samples and words are explicit external bus inputs, consumed by original instructions. The 3030 hotkey on any of the three published controller positions executes the real boot initialization and complete decompression. The contract stops at decoded startup 7EAF0B, before that program executes, matching the existing boot proof. No return or completed gameplay reset is invented.

The initial smoke exposed only a final accumulator error in the new boot adapter: native C14CF3 and C14D40 form two JSR frames, and decoder C14CB7 TSC/ADC33 leaves A=01F8 before PLP/PLD. Correcting the adapter's earlier 01FA assumption left every frozen dependency intact. The corrected 24-case smoke and first complete 4,136-call capture passed. These are four returning entries ×256 interface contexts ×four bus/assignment/HUD contexts, 36 directed hotkey transfers (three published pad positions ×three entry wrappers ×four caller contexts), and four direct reset transfers. Including naturally occurring hotkeys, 49 calls transferred to 7EAF0B. The returning and transition cases executed 1,026 real NMI events, at most one per case.

Interior calls use D=0/DB=00; preserving/public wrappers cover incoming D=0000/0300/0100/1800, DB=00/7E/7F/42 and M/X width combinations. The check compares full WRAM excluding only the separately observed occupied caller and bootstrap stack regions, all CPU/status/S/D/DB, graphics/arithmetic peripherals, acknowledgement state and serial bus order. Caller watermarks are 1ED4/1ED7/1EDD/1EDF/1EFB; bootstrap watermark is 01BD. No hook substitutes a routine.

The primary capture has 822 PC/M/X states and 123 dependency fingerprints. Immediate-width/boundary recovery passes all five catalogue bodies. Instruction-start observation is 109/111: C093E3 STZ46 awaits a separate directed invalid-third-pad supplement; C093B8 is the unreachable RTS described above and is deliberately not claimed as executed. The primary tool/report/capture are frozen. General UI/menu construction and decoded startup after 7EAF0B remain separate work.

Integration/interface: `GameControllerPoll.poll_controller_edges(depth)` supports the existing native call depth; `poll_controllers(depth)` preserves the caller; terminal cold reset sets `reset_target=0x7EAF0B`. `setup_controller_poll_fixture` and `ControllerInputCPU` provide reusable native assignment/bus/NMI context. Consumers must propagate the terminal reset instead of returning from it.

| Artifact | SHA-256 |
|---|---|
| tools/game_controller_poll.py | ffac42537c23028a48845db442acb845e10bbcc0630c7ee0bba7fcd431b8b66c |
| data/game_controller_poll.json | 2d73394f3053bf087935dff755e16a687df57a84249a2b809b1499f9fc777f0f |
| data/game_controller_poll.coverage.json | ee34fec30ab54b25e8ed1bac280e4f1d430b0826def1b9a803ad9f10036087ad |


## Directed third-pad supplement

The independent `game_controller_poll_guard.py` smoke (2 cases) and eight native calls passed unchanged. It supplies an invalid low nibble in the third Multi5 automatic word and captures the actual C093E3 STZ46 with M16/X8. Its 303 PC/M/X states and 124 dependency fingerprints supplement the frozen primary capture without repeating it. Combined proof observes all 110/110 starts in the 204 live bytes; the one static, unreachable C093B8 RTS remains excluded from live source credit. Five live ranges pass immediate-width/boundary recovery. The supplement adds no independent instruction bytes.

| Supplement artifact | SHA-256 |
|---|---|
| tools/game_controller_poll_guard.py | 363b3877c58273e6761c973b67fa6a26082e5ff096abe15f9b2271b01f3c0b52 |
| data/game_controller_poll_guard.json | c050e6a1885988a34cc85e63e9e130928c2af739a323049ff75ae7767760bf1f |
| data/game_controller_poll_guard.coverage.json | 807465cf4c31e8e584bd62fec1fc643103bc3f5670361cebab2a5d13e33a02da |

Physical source reconstruction retains the exact1-byte RTS atC093B8, explicitly tagged in data/source_checkpoint_20261010_controllers_chest.json as static and unexecuted by the normal reset contract. Thus205 exact source bytes comprise204 live modeled bytes and1 statically understood tail, with no fabricated CPU entry or return.
