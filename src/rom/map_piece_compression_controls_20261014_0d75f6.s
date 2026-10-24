.setcpu "65816"
.segment "CODE"
.org $75F6
map_control_0d75f6:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
