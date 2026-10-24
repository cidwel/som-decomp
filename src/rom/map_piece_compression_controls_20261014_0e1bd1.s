.setcpu "65816"
.segment "CODE"
.org $1BD1
map_control_0e1bd1:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
