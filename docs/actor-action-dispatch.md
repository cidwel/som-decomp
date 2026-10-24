# Current actor-action selection

The readable selector closes 118 instruction bytes in three ranges: C1D94D/69, C1DA22/18 and C1DABE/31. Its 1,828 original comparisons observe all 54 instruction starts. Evidence is frozen in `data/actor_action_dispatch_proof.json`, its coverage companion and `data/actor_action_dispatch_audit.json`.

| Action | Native consumer |
| --- | --- |
| 00 | Return without an action. |
| 01 | Clear the previous directional pose. |
| 02 | Enter the direct-target attack wrapper. |
| 03, 06 | Enter the guarded party-attack variant. |
| 04 | Disable the actor. |
| 05 | Clone a spare actor and refresh resources. |
| 07 | Clear charge and install the idle party gauge. |
| 40 | Install an animation pose. |
| 41, 42 | Return. |
| 43 | Clone with the command-selected identity. |
| 44 | Prepare the cast pose and real cast-request state. |
| 81 | Replace identity and reset movement. |
| C0 | Publish the three audio operands and execute the real audio sender. |
| C1 | Apply the directional command. |
| Other byte values | Return through the native comparison guards. |

Selection preserves the original comparisons and flags, including bit 40 classification and the ordered equality checks. It composes the previously frozen complete action consumers, program initialization, and music/nonmusic audio models. The audio path covers all 256 audio command bytes, including song loading and preset expansion, with song 18, parameter 04 and volume 0F in a native boot-derived audio workspace. Audio acknowledgements are explicit inputs; this does not add an SPC timing claim.

The C0 action ends in literal RTS at C1DADC, while the surrounding dispatcher normally returns with RTL. With the genuine three-byte caller frame at stack 1700, its RTS leaves S=16FF and the saved return-bank byte still on the stack. The model records this short return and the checker requires that exact result. Other actions restore S=1700. The original instruction is preserved, not changed to RTL.

The primary selector is entered after the original saved-X restoration, at the actual C1D94D instruction boundary. All 256 action bytes are tested over six aligned actors; additional cases enter the five pose branches and the audio/direction branch directly. Full WRAM outside the observed native stack, CPU/context/peripherals, audio acknowledgement state and ordered writes match without instruction hooks.

The leading C1D942..C1D94C prefix remains open. It clears E064 and calls C10028/C12552 to step the actor program before restoring X. These comparisons prove the selection and complete consumers after that prefix; they do not establish the full actor-program interpreter or the whole game scheduler.
