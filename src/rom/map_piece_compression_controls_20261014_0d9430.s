.setcpu "65816"
.segment "CODE"
.org $9430
map_control_0d9430:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
