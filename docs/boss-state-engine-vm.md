# Boss-state bootstrap and command dispatcher

`tools/boss_state_engine_vm.py` reconstructs C2377A/C237C7: 82 instruction bytes and 44 numeric dispatch bytes. A request matching current state 7A returns immediately. A changed request stores the state, obtains the script pointer from the actor's table 76 in bank C2, clears eleven transient motion/control fields, and interprets byte commands until FF. Each command increments its cursor before dispatching through the original 22-word table; jumps and operand handlers preserve their actual cursor/register behavior.

The interpreter composes verified command models by their explicit APIs. This matters because field handlers read word operands while projectile creation reads three byte operands; using one inherited operand method for both changes script traversal. The external actor command, attack-row preparation, sound request, projectile/native creation and ordinary field/orientation/spell commands execute through their complete existing models.

## Evidence

`data/boss_state_engine_vm.json` records 1,920 complete original calls without bypass hooks: 512 bootstrap calls and all 22 command opcodes × 64 real dispatch calls. Bootstrap samples all 32 inferred descriptor-zero table indices: even indices execute changed-state scripts and odd indices exercise the unchanged-state return. It does not claim that all 32 scripts were interpreted. Direct dispatch covers every command, including actual native callback C23E7F, real projectile allocation/resource setup, selected external command's negative gate, attack preparation and ordered audio requests.

All 34 instruction starts in the proposed ranges occur in coverage. Tool/ROM/CPU and 88 dependency hashes match the evidence. Verification compares full 128 KiB WRAM outside the 129-byte caller-stack window, nine CPU result fields, S/D/DB, static peripherals and audio writes. Fixtures include nine incoming/selected actor slots, all 512 pool occupancy masks, WRAM operand banks 7E/7F, Y wrapping and long word-read carry. Source zero is used for bank 7F to avoid generating operands that instead fall into bank-80 ROM.

## Limits

Native context is D0200/DB7E/M16/X16/binary with C5 zero/C7 FFFF. The external-command opcode uses a negative selected-actor gate here; the command body itself has separate complete proof. Native callbacks outside C23E7F and other descriptor tables require additional composition. The principal parent controller C234D8 and combined combat/definition/animation pool updates are the next frontier; closing this interpreter alone does not prove continuous boss frames. Original scripts remain in ROM and are not saved as payload artifacts.

The82 instruction bytes are new matching sources. The44-byte dispatch table was already independently assembled as `src/rom/boss_state_command_handler_pointers.s`; the integrated component reuses it with zero duplicate data-byte credit.
