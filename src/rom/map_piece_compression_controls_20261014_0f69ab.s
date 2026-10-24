.setcpu "65816"
.segment "CODE"
.org $69AB
map_control_0f69ab:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
