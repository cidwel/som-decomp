.setcpu "65816"
.segment "CODE"
.org $715B
map_control_0e715b:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
