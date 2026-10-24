.setcpu "65816"
.segment "CODE"
.org $0D6B
map_control_0d0d6b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
