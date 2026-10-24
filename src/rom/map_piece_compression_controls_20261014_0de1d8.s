.setcpu "65816"
.segment "CODE"
.org $E1D8
map_control_0de1d8:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
