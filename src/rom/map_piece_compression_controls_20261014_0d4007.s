.setcpu "65816"
.segment "CODE"
.org $4007
map_control_0d4007:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
