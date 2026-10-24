.setcpu "65816"
.segment "CODE"
.org $EAE2
map_control_0eeae2:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
