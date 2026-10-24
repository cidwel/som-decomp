.setcpu "65816"
.segment "CODE"
.org $7E29
map_control_0d7e29:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
