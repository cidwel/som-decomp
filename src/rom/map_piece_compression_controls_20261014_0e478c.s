.setcpu "65816"
.segment "CODE"
.org $478C
map_control_0e478c:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
