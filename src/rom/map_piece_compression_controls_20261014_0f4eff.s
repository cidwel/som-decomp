.setcpu "65816"
.segment "CODE"
.org $4EFF
map_control_0f4eff:
    .byte $C1 ; same-value copy count/distance
