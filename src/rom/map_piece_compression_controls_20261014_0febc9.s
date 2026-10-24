.setcpu "65816"
.segment "CODE"
.org $EBC9
map_control_0febc9:
    .byte $EF ; backreference distance high bits
    .byte $0F ; distance low bit/count
