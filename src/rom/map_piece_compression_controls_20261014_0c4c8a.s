.setcpu "65816"
.segment "CODE"
.org $4C8A
map_control_0c4c8a:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
