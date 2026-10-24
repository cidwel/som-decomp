.setcpu "65816"
.segment "CODE"
.org $FAFE
map_control_0cfafe:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
