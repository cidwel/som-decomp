.setcpu "65816"
.segment "CODE"
.org $849A
map_control_0d849a:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
