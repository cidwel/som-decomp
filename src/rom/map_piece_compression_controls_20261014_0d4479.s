.setcpu "65816"
.segment "CODE"
.org $4479
map_control_0d4479:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
