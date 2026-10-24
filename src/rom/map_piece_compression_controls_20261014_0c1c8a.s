.setcpu "65816"
.segment "CODE"
.org $1C8A
map_control_0c1c8a:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
