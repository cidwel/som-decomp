.setcpu "65816"
.segment "CODE"
.org $0A26
map_control_0f0a26:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
