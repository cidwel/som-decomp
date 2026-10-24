.setcpu "65816"
.segment "CODE"
.org $593A
map_control_0f593a:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
