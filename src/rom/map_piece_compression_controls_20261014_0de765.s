.setcpu "65816"
.segment "CODE"
.org $E765
map_control_0de765:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
