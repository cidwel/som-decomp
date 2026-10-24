.setcpu "65816"
.segment "CODE"
.org $FABD
map_control_0cfabd:
    .byte $F1 ; progressive-copy count
