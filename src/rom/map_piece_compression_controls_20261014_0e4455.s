.setcpu "65816"
.segment "CODE"
.org $4455
map_control_0e4455:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
