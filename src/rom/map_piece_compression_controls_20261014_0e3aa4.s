.setcpu "65816"
.segment "CODE"
.org $3AA4
map_control_0e3aa4:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
