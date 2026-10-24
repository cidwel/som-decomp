.setcpu "65816"
.segment "CODE"
.org $6A45
map_control_0f6a45:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
