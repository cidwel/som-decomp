.setcpu "65816"
.segment "CODE"
.org $DF04
map_control_0ddf04:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
