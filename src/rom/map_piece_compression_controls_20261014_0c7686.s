.setcpu "65816"
.segment "CODE"
.org $7686
map_control_0c7686:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
