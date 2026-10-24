.setcpu "65816"
.segment "CODE"
.org $69D6
map_control_0e69d6:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
