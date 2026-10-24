.setcpu "65816"
.segment "CODE"
.org $2B29
map_control_0c2b29:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
