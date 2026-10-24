.setcpu "65816"
.segment "CODE"
.org $5E1B
map_control_0f5e1b:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
