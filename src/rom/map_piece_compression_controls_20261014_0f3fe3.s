.setcpu "65816"
.segment "CODE"
.org $3FE3
map_control_0f3fe3:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $5A ; distance low bit/count
