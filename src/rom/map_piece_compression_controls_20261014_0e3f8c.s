.setcpu "65816"
.segment "CODE"
.org $3F8C
map_control_0e3f8c:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
