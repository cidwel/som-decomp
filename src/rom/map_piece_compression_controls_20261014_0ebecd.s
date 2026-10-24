.setcpu "65816"
.segment "CODE"
.org $BECD
map_control_0ebecd:
    .byte $F1 ; progressive-copy count
