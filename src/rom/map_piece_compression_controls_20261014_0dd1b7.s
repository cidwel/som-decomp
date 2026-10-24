.setcpu "65816"
.segment "CODE"
.org $D1B7
map_control_0dd1b7:
    .byte $DA ; same-value copy count/distance
    .byte $DD ; same-value copy count/distance
