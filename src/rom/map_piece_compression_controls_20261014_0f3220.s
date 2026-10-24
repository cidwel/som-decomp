.setcpu "65816"
.segment "CODE"
.org $3220
map_control_0f3220:
    .byte $C1 ; same-value copy count/distance
    .byte $DA ; same-value copy count/distance
