.setcpu "65816"
.segment "CODE"
.org $0AA7
map_control_0d0aa7:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
