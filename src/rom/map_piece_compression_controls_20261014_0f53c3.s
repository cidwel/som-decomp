.setcpu "65816"
.segment "CODE"
.org $53C3
map_control_0f53c3:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
