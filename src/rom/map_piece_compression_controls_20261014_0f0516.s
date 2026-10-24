.setcpu "65816"
.segment "CODE"
.org $0516
map_control_0f0516:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
