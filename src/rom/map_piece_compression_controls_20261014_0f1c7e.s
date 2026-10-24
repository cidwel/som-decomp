.setcpu "65816"
.segment "CODE"
.org $1C7E
map_control_0f1c7e:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
