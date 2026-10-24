.setcpu "65816"
.segment "CODE"
.org $6FE4
map_control_0f6fe4:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
