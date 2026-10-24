.setcpu "65816"
.segment "CODE"
.org $D693
map_control_0ed693:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
