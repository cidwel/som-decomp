.setcpu "65816"
.segment "CODE"
.org $8EF6
map_control_0e8ef6:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
