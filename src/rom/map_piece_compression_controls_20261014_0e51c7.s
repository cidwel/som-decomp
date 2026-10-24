.setcpu "65816"
.segment "CODE"
.org $51C7
map_control_0e51c7:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
