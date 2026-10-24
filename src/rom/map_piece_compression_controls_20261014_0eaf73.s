.setcpu "65816"
.segment "CODE"
.org $AF73
map_control_0eaf73:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
