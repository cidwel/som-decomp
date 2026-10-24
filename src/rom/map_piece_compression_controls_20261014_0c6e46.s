.setcpu "65816"
.segment "CODE"
.org $6E46
map_control_0c6e46:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
