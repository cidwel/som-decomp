.setcpu "65816"
.segment "CODE"
.org $5AD0
map_control_0f5ad0:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
