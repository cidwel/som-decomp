.setcpu "65816"
.segment "CODE"
.org $4068
map_control_0d4068:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
