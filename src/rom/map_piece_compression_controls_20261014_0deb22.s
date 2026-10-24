.setcpu "65816"
.segment "CODE"
.org $EB22
map_control_0deb22:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
