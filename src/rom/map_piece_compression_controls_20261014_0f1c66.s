.setcpu "65816"
.segment "CODE"
.org $1C66
map_control_0f1c66:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
