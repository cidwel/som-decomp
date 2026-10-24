.setcpu "65816"
.segment "CODE"
.org $607E
map_control_0f607e:
    .byte $C1 ; same-value copy count/distance
    .byte $DA ; same-value copy count/distance
