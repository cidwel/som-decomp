.setcpu "65816"
.segment "CODE"
.org $822D
map_control_0d822d:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
