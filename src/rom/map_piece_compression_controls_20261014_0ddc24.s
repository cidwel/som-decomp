.setcpu "65816"
.segment "CODE"
.org $DC24
map_control_0ddc24:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
