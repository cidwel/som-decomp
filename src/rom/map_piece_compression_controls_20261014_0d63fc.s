.setcpu "65816"
.segment "CODE"
.org $63FC
map_control_0d63fc:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
