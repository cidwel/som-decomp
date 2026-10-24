.setcpu "65816"
.segment "CODE"
.org $0D7C
map_control_0f0d7c:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
