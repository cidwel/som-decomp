.setcpu "65816"
.segment "CODE"
.org $8D34
map_control_0e8d34:
    .byte $C2 ; same-value copy count/distance
    .byte $F2 ; progressive-copy count
