.setcpu "65816"
.segment "CODE"
.org $00D2
map_control_0e00d2:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
