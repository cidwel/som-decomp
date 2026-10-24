.setcpu "65816"
.segment "CODE"
.org $D712
map_control_0dd712:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
