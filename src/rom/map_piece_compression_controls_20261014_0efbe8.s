.setcpu "65816"
.segment "CODE"
.org $FBE8
map_control_0efbe8:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
