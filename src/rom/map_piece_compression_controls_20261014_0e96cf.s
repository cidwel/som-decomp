.setcpu "65816"
.segment "CODE"
.org $96CF
map_control_0e96cf:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
