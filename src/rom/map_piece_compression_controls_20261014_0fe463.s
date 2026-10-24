.setcpu "65816"
.segment "CODE"
.org $E463
map_control_0fe463:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
