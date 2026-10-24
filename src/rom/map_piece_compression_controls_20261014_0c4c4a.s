.setcpu "65816"
.segment "CODE"
.org $4C4A
map_control_0c4c4a:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
