.setcpu "65816"
.segment "CODE"
.org $0A46
map_control_0f0a46:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
