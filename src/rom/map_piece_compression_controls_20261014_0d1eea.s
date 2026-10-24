.setcpu "65816"
.segment "CODE"
.org $1EEA
map_control_0d1eea:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
