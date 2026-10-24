.setcpu "65816"
.segment "CODE"
.org $62CF
map_control_0f62cf:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
