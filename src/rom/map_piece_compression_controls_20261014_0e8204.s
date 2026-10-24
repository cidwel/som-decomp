.setcpu "65816"
.segment "CODE"
.org $8204
map_control_0e8204:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
