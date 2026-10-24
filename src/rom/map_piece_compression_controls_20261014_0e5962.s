.setcpu "65816"
.segment "CODE"
.org $5962
map_control_0e5962:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
