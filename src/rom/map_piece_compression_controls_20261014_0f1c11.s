.setcpu "65816"
.segment "CODE"
.org $1C11
map_control_0f1c11:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
