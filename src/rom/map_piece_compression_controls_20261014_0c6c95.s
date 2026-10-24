.setcpu "65816"
.segment "CODE"
.org $6C95
map_control_0c6c95:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
