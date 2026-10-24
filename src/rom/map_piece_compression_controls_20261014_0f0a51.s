.setcpu "65816"
.segment "CODE"
.org $0A51
map_control_0f0a51:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
