.setcpu "65816"
.segment "CODE"
.org $DC01
map_control_0ddc01:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
