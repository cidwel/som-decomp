.setcpu "65816"
.segment "CODE"
.org $4ABC
map_control_0c4abc:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
