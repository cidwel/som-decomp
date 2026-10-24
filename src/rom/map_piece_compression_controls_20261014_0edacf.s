.setcpu "65816"
.segment "CODE"
.org $DACF
map_control_0edacf:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
