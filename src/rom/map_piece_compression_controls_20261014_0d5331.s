.setcpu "65816"
.segment "CODE"
.org $5331
map_control_0d5331:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
