.setcpu "65816"
.segment "CODE"
.org $7C5B
map_control_0e7c5b:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
