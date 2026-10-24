.setcpu "65816"
.segment "CODE"
.org $4BD2
map_control_0d4bd2:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
