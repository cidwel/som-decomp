.setcpu "65816"
.segment "CODE"
.org $30A4
map_control_0d30a4:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
