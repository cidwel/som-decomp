.setcpu "65816"
.segment "CODE"
.org $CF0A
map_control_0ecf0a:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
