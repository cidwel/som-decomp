.setcpu "65816"
.segment "CODE"
.org $6FCC
map_control_0f6fcc:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
