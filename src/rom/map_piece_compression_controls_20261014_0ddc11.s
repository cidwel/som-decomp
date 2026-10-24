.setcpu "65816"
.segment "CODE"
.org $DC11
map_control_0ddc11:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
