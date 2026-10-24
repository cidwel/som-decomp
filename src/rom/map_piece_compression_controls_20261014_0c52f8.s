.setcpu "65816"
.segment "CODE"
.org $52F8
map_control_0c52f8:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
