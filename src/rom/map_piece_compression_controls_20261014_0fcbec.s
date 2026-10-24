.setcpu "65816"
.segment "CODE"
.org $CBEC
map_control_0fcbec:
    .byte $D4 ; same-value copy count/distance
