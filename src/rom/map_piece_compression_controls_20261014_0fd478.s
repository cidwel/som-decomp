.setcpu "65816"
.segment "CODE"
.org $D478
map_control_0fd478:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
