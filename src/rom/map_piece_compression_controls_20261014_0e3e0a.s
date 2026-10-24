.setcpu "65816"
.segment "CODE"
.org $3E0A
map_control_0e3e0a:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
