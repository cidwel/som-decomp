.setcpu "65816"
.segment "CODE"
.org $ED08
map_control_0fed08:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
