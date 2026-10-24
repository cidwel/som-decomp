.setcpu "65816"
.segment "CODE"
.org $DFC2
map_control_0fdfc2:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
