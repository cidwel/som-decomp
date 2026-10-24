# Actor action-command consumers

Nine readable CPU models close 282 instruction bytes used by the native action dispatcher. Their original executions pass 216 comparisons, with all 107 instruction starts observed. The frozen evidence is `data/actor_action_commands_proof.json`, its coverage companion and `data/actor_action_commands_audit.json`.

| Entry | Bytes | Effect |
| --- | ---: | --- |
| C1D992 | 9 | Disable the actor and clear its graphics allocation marker. |
| C1D99B | 12 | Mark a direct attack and enter the real C0B287 attack wrapper. |
| C1D9A7 | 29 | Clear a previous directional pose only when E067 is set. |
| C1D9C4 | 31 | Find a spare record, clone three field groups, assign palette rows and refresh identity, graphics and program. |
| C1D9E3 | 29 | Admit a party attack only below actor offset 0600, with ED negative and both busy fields clear. |
| C1DA00 | 34 | Install the animation pose and execute the real cast-request preparation. |
| C1DA34 | 32 | Install the animation pose; includes the adjacent return used by the clone guard. |
| C1DA54 | 48 | Clone into a spare record and install the command-selected identity and graphics. |
| C1DA84 | 58 | Replace an actor identity, rebuild graphics and palette, then reset movement fields. |

The model composes previously frozen attack, target, palette, spare-record, cache, graphics, identity and cast models. Cloning preserves the native field-group gaps and destination nibble, operates on the selected destination, and restores the caller's actor offset after resource installation. Failed spare selection returns without fabricating a successful clone. Ordinary and selected-identity clones use different resource sequences.

The comparisons cover six aligned actor records, four identity values, both palette pages, positive and negative ED, busy gates, free and offscreen spare records, and previous-pose state. Each call compares full WRAM outside the observed native stack, returned registers and flags, context, peripherals and ordered audio. Entry contract: M8, X16, D0, DB7E, binary arithmetic; there are no instruction hooks. Recursive dependency hashes are revalidated by the audit.

C1D942 itself remains open: these consumers do not establish complete execution of C10028/C12552 actor-program stepping. The separate sound command's literal RTS and the dispatch prefix also remain unclaimed. Source availability for these consumers is not a claim that the full scheduler or game has been reconstructed.
