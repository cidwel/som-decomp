.setcpu "65816"
.segment "CODE"
.org $6988
map_control_0f6988:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
