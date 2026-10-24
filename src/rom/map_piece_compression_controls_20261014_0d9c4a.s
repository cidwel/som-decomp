.setcpu "65816"
.segment "CODE"
.org $9C4A
map_control_0d9c4a:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
