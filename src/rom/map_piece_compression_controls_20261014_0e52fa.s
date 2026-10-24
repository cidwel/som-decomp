.setcpu "65816"
.segment "CODE"
.org $52FA
map_control_0e52fa:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
