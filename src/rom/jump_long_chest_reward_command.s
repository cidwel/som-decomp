; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-chest-reward.md.
.setcpu "65816"
.smart
.a8
.i16

open_chest_and_select_reward_or_existing_notice = $C8E0B0

.segment "CODE"
.org $386A
jump_long_chest_reward_command:
    jml f:open_chest_and_select_reward_or_existing_notice
