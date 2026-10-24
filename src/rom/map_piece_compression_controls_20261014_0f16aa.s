.setcpu "65816"
.segment "CODE"
.org $16AA
map_control_0f16aa:
    .byte $C1 ; same-value copy count/distance
