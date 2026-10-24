.setcpu "65816"
.segment "CODE"
.org $0788
map_control_0f0788:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
