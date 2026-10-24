.setcpu "65816"
.segment "CODE"
.org $0975
map_control_0f0975:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
