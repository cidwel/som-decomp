.setcpu "65816"
.segment "CODE"
.org $1CD8
map_control_0f1cd8:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
