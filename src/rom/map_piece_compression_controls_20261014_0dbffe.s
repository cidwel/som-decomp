.setcpu "65816"
.segment "CODE"
.org $BFFE
map_control_0dbffe:
    .byte $F1 ; progressive-copy count
