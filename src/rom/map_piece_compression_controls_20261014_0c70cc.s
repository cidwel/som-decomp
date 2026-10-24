.setcpu "65816"
.segment "CODE"
.org $70CC
map_control_0c70cc:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
