# Native periodic party-message queue

`PartyMessageQueue` reconstructs the public C0005D/3 and internal C03845/3 jump aliases, complete C057C9..C058AE/230 body, and C05BEA/14 and C05BF8/14 script-request helpers: 264 instruction bytes, no new tables or assets. A real event-side caller at C2C792 enters this public API when DP48 and DPD0 are both zero; its complete enclosing body C2C786..C2C7B1 is a separate next reconstruction.

The update first calls the complete native dialogue coordinator C00092/C00113. It then establishes D0300/DB7E, advances the actual additive RNG including scratch CC and status/index restoration, and evaluates party suspension, dialogue activity and countdown. Its twelve-record queue uses native hardware multiplication to locate 30-byte records. Empty records request resume, unavailable dialogue requests suspend, and eligible records update actor-status guards, copy 30 bytes into FF69, derive a countdown through hardware multiplication and clear the selected record. Selector11 wraps to0. Record sign and A3 count control the actor E190 mask guard; no synthetic successful callback is supplied.

## Evidence

Directed smoke case6 and full16 both returned terminal exit0. The frozen report and coverage in `data/event_party_message_queue_proof.*` contain 3,125 original instructions with no hooks. They exercise suspension, active dialogue, countdown1, empty records with dialogue off/on, suspend request, positive/negative records, actor mask absent/present, selector11 wrap, both aliases, a real dialogue phase53 producer and both request helpers. RNG indices0/14 are included. Full WRAM/SRAM/CPU/context, hardware, input and audio effects agree outside the observed stack frames.

`data/event_party_message_queue_audit.json` verifies all 129 own starts, 279 PC/M/X states and 175 unchanged dependency hashes. Models, checker and captured evidence are frozen after this result. The dialogue coordinator and other existing callees contribute no duplicate source credit. Independent physical source recovery and joint assembly remain required.

The captured queue domain is D0300/DB7E/M8/X16, binary arithmetic, selector0..11 and valid actor offsets. Directed dialogue-state producers do not claim every gameplay trajectory or close the unrelated general interactive menu/event1F branches. Records and native script strings are consumed from the supplied ROM and WRAM; no payload is added to source credit.
