.setcpu "65816"
.segment "CODE"
.org $6191
map_control_0f6191:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
