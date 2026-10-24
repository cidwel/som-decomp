.setcpu "65816"
.segment "CODE"
.org $2CE5
map_control_0e2ce5:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
