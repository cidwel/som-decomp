.setcpu "65816"
.segment "CODE"
.org $5BC7
map_control_0f5bc7:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
