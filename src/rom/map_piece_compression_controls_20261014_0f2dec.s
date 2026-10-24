.setcpu "65816"
.segment "CODE"
.org $2DEC
map_control_0f2dec:
    .byte $C1 ; same-value copy count/distance
