.setcpu "65816"
.segment "CODE"
.org $3B83
map_control_0e3b83:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
