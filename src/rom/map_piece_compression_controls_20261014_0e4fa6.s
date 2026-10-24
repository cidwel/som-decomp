.setcpu "65816"
.segment "CODE"
.org $4FA6
map_control_0e4fa6:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
