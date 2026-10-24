.setcpu "65816"
.segment "CODE"
.org $CF73
map_control_0ecf73:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
