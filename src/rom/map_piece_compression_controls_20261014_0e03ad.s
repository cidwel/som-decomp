.setcpu "65816"
.segment "CODE"
.org $03AD
map_control_0e03ad:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
