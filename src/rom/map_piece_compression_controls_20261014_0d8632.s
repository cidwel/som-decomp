.setcpu "65816"
.segment "CODE"
.org $8632
map_control_0d8632:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
