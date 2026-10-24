.setcpu "65816"
.segment "CODE"
.org $51C6
map_control_0d51c6:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
