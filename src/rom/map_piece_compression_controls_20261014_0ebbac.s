.setcpu "65816"
.segment "CODE"
.org $BBAC
map_control_0ebbac:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
