.setcpu "65816"
.segment "CODE"
.org $4812
map_control_0d4812:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
