.setcpu "65816"
.segment "CODE"
.org $F0AA
map_control_0ef0aa:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
