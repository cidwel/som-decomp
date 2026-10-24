.setcpu "65816"
.segment "CODE"
.org $1037
map_control_0f1037:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
