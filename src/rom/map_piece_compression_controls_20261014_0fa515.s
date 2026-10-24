.setcpu "65816"
.segment "CODE"
.org $A515
map_control_0fa515:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
