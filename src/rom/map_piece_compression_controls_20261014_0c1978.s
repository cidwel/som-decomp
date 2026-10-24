.setcpu "65816"
.segment "CODE"
.org $1978
map_control_0c1978:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
