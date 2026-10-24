.setcpu "65816"
.segment "CODE"
.org $0EB8
map_control_0e0eb8:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
