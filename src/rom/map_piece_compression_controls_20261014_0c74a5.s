.setcpu "65816"
.segment "CODE"
.org $74A5
map_control_0c74a5:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
