.setcpu "65816"
.segment "CODE"
.org $D335
map_control_0ed335:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
