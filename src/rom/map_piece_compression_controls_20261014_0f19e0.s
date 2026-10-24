.setcpu "65816"
.segment "CODE"
.org $19E0
map_control_0f19e0:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
