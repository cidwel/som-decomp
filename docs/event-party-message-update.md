# Event-side periodic party-message consumer

`PartyMessageUpdate` reconstructs the complete C2C786..C2C7B1 body (44 bytes) and the C00003/3 and C00083/3 public preemptive-dialogue aliases: 50 instruction bytes, no new data. Its idle branch tests the actual direct-page request byte48 and event byteD0 before calling the complete party-message queue through C0005D. Its requested-dialogue branch reloads actor offsetD4 into X, preserves DB, calls the complete preemptive dialogue coordinator C0012C, then tests actual dialogue activity1D04. Active dialogue retains request48; inactive dialogue clears it. The intermediate010E word read and native register/flag effects are retained.

## Evidence

Smoke case0 and the first full ten-call capture both returned terminal exit0. `data/event_party_message_update_proof.json` and its coverage record 1,105 original instructions, without hooks. Directed producers include idle positive records and paused/empty/countdown queues, a busy event, preemptive inactive/active dialogue, a native phase53 dialogue producer and both public aliases. Full WRAM/SRAM/CPU/context, hardware, audio and input effects agree outside the observed stack frames.

`data/event_party_message_update_audit.json` verifies 24/24 own starts, 291 PC/M/X states and 177 unchanged dependency hashes. The Queue264 and dialogue models are frozen dependencies; their bytes are not credited again. Models, checker and captured evidence are frozen after this result. Independent physical source recovery and joint assembly remain required.

The captured producer domain is D0300/DB7E/M8/X16 and binary arithmetic. This closes the consumer's complete directed call chains, rather than a general map frame or all event1F menu/reset branches.
