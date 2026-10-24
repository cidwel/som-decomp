; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-chest-reward.md.
.setcpu "65816"
.smart
.a8
.i16

jump_long_chest_reward_command = $386A

.segment "CODE"
.org $384E
jump_native_chest_reward_command:
    jmp jump_long_chest_reward_command
