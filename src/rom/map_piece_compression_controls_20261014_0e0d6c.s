.setcpu "65816"
.segment "CODE"
.org $0D6C
map_control_0e0d6c:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
