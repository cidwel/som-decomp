.setcpu "65816"
.segment "CODE"
.org $46DE
map_control_0d46de:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
