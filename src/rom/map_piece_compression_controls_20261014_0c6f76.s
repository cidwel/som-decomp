.setcpu "65816"
.segment "CODE"
.org $6F76
map_control_0c6f76:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
