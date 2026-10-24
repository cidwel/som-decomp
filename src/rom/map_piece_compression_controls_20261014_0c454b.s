.setcpu "65816"
.segment "CODE"
.org $454B
map_control_0c454b:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
