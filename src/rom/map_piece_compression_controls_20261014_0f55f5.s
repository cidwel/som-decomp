.setcpu "65816"
.segment "CODE"
.org $55F5
map_control_0f55f5:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
