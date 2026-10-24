.setcpu "65816"
.segment "CODE"
.org $1C1C
map_control_0f1c1c:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
