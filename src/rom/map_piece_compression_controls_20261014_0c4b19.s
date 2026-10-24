.setcpu "65816"
.segment "CODE"
.org $4B19
map_control_0c4b19:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
