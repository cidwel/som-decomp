.setcpu "65816"
.segment "CODE"
.org $85E1
map_control_0d85e1:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
