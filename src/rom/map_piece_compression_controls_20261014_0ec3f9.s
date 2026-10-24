.setcpu "65816"
.segment "CODE"
.org $C3F9
map_control_0ec3f9:
    .byte $C1 ; same-value copy count/distance
    .byte $DA ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
