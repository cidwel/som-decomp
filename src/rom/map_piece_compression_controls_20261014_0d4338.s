.setcpu "65816"
.segment "CODE"
.org $4338
map_control_0d4338:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
