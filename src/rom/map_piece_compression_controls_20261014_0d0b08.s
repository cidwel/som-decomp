.setcpu "65816"
.segment "CODE"
.org $0B08
map_control_0d0b08:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
