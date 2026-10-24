.setcpu "65816"
.segment "CODE"
.org $CDEA
map_control_0fcdea:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
