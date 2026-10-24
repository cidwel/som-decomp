; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-chest-reward.md.
.setcpu "65816"
.smart
.a8
.i16

jump_native_chest_reward_command = $384E

.segment "CODE"
.org $0066
jump_public_chest_reward_command:
    jmp jump_native_chest_reward_command
