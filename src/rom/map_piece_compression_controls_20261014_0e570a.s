.setcpu "65816"
.segment "CODE"
.org $570A
map_control_0e570a:
    .byte $F1 ; progressive-copy count
    .byte $C7 ; same-value copy count/distance
