.setcpu "65816"
.segment "CODE"
.org $4594
map_control_0d4594:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
