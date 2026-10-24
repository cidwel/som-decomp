.setcpu "65816"
.segment "CODE"
.org $ED74
map_control_0eed74:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
