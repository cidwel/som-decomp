.setcpu "65816"
.segment "CODE"
.org $13F5
map_control_0f13f5:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
