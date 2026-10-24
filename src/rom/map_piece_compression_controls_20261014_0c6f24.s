.setcpu "65816"
.segment "CODE"
.org $6F24
map_control_0c6f24:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
