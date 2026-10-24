.setcpu "65816"
.segment "CODE"
.org $6B43
map_control_0d6b43:
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
