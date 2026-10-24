.setcpu "65816"
.segment "CODE"
.org $D780
map_control_0fd780:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
