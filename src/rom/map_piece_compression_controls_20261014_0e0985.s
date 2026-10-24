.setcpu "65816"
.segment "CODE"
.org $0985
map_control_0e0985:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
