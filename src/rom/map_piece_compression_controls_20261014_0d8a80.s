.setcpu "65816"
.segment "CODE"
.org $8A80
map_control_0d8a80:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
