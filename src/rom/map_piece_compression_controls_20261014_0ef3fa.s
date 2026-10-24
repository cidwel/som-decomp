.setcpu "65816"
.segment "CODE"
.org $F3FA
map_control_0ef3fa:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $BD ; row-distance/count
