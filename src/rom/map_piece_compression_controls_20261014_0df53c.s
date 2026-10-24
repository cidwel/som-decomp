.setcpu "65816"
.segment "CODE"
.org $F53C
map_control_0df53c:
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
