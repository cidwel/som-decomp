.setcpu "65816"
.segment "CODE"
.org $2BDE
map_control_0f2bde:
    .byte $C1 ; same-value copy count/distance
    .byte $DA ; same-value copy count/distance
