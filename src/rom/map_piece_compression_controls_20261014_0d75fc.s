.setcpu "65816"
.segment "CODE"
.org $75FC
map_control_0d75fc:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
