.setcpu "65816"
.segment "CODE"
.org $594A
map_control_0c594a:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
