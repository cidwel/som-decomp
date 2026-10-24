.setcpu "65816"
.segment "CODE"
.org $3B14
map_control_0e3b14:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
