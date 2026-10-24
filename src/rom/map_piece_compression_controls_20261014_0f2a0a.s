.setcpu "65816"
.segment "CODE"
.org $2A0A
map_control_0f2a0a:
    .byte $C3 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
