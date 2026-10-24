.setcpu "65816"
.segment "CODE"
.org $D7EB
map_control_0fd7eb:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
