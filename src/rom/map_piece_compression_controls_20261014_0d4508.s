.setcpu "65816"
.segment "CODE"
.org $4508
map_control_0d4508:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
