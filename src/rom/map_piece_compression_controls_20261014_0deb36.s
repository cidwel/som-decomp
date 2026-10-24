.setcpu "65816"
.segment "CODE"
.org $EB36
map_control_0deb36:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
