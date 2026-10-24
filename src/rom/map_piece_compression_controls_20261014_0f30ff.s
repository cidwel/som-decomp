.setcpu "65816"
.segment "CODE"
.org $30FF
map_control_0f30ff:
    .byte $F1 ; progressive-copy count
    .byte $C9 ; same-value copy count/distance
