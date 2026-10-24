.setcpu "65816"
.segment "CODE"
.org $5822
map_control_0f5822:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
