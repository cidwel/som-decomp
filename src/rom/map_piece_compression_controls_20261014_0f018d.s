.setcpu "65816"
.segment "CODE"
.org $018D
map_control_0f018d:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2B ; distance low bit/count
