.setcpu "65816"
.segment "CODE"
.org $51E5
map_control_0d51e5:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
