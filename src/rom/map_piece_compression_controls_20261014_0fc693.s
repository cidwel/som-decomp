.setcpu "65816"
.segment "CODE"
.org $C693
map_control_0fc693:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
