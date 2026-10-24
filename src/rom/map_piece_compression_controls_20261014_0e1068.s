.setcpu "65816"
.segment "CODE"
.org $1068
map_control_0e1068:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
