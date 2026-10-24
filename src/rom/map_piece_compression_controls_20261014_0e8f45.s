.setcpu "65816"
.segment "CODE"
.org $8F45
map_control_0e8f45:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
