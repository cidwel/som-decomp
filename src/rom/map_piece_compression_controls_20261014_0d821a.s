.setcpu "65816"
.segment "CODE"
.org $821A
map_control_0d821a:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
