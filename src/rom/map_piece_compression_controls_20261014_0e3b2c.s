.setcpu "65816"
.segment "CODE"
.org $3B2C
map_control_0e3b2c:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
