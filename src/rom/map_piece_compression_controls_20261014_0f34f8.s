.setcpu "65816"
.segment "CODE"
.org $34F8
map_control_0f34f8:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
