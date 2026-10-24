.setcpu "65816"
.segment "CODE"
.org $0A3B
map_control_0f0a3b:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
