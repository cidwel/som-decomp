.setcpu "65816"
.segment "CODE"
.org $C8F9
map_control_0ec8f9:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
