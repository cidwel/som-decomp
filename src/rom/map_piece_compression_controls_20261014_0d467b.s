.setcpu "65816"
.segment "CODE"
.org $467B
map_control_0d467b:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
