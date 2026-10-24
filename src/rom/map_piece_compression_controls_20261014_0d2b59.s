.setcpu "65816"
.segment "CODE"
.org $2B59
map_control_0d2b59:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
