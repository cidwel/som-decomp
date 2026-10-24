.setcpu "65816"
.segment "CODE"
.org $5AB5
map_control_0f5ab5:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
