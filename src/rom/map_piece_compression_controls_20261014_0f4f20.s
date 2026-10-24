.setcpu "65816"
.segment "CODE"
.org $4F20
map_control_0f4f20:
    .byte $C1 ; same-value copy count/distance
