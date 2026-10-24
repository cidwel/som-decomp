.setcpu "65816"
.segment "CODE"
.org $6847
map_control_0f6847:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
