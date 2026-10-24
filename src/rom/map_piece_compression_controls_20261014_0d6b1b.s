.setcpu "65816"
.segment "CODE"
.org $6B1B
map_control_0d6b1b:
    .byte $F1 ; progressive-copy count
    .byte $D2 ; same-value copy count/distance
