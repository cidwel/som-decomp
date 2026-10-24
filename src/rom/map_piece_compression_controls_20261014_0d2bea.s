.setcpu "65816"
.segment "CODE"
.org $2BEA
map_control_0d2bea:
    .byte $C1 ; same-value copy count/distance
    .byte $DA ; same-value copy count/distance
