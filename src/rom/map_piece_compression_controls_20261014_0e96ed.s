.setcpu "65816"
.segment "CODE"
.org $96ED
map_control_0e96ed:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
