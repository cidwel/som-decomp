.setcpu "65816"
.segment "CODE"
.org $1CC1
map_control_0f1cc1:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
