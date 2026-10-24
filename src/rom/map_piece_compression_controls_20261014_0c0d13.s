.setcpu "65816"
.segment "CODE"
.org $0D13
map_control_0c0d13:
    .byte $D2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $D5 ; same-value copy count/distance
