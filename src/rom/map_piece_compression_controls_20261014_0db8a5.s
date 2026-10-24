.setcpu "65816"
.segment "CODE"
.org $B8A5
map_control_0db8a5:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
