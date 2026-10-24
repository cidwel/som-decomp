.setcpu "65816"
.segment "CODE"
.org $0B69
map_control_0f0b69:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
