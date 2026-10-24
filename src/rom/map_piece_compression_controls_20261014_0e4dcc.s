.setcpu "65816"
.segment "CODE"
.org $4DCC
map_control_0e4dcc:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
