.setcpu "65816"
.segment "CODE"
.org $7090
map_control_0e7090:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
