.setcpu "65816"
.segment "CODE"
.org $8623
map_control_0e8623:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
