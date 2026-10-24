.setcpu "65816"
.segment "CODE"
.org $3FF8
map_control_0e3ff8:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
