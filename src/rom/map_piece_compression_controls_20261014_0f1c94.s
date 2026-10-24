.setcpu "65816"
.segment "CODE"
.org $1C94
map_control_0f1c94:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
