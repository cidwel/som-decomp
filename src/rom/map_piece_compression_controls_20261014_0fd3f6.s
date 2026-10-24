.setcpu "65816"
.segment "CODE"
.org $D3F6
map_control_0fd3f6:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
