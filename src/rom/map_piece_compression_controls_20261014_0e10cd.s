.setcpu "65816"
.segment "CODE"
.org $10CD
map_control_0e10cd:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
