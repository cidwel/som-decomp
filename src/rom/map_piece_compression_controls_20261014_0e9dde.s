.setcpu "65816"
.segment "CODE"
.org $9DDE
map_control_0e9dde:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
