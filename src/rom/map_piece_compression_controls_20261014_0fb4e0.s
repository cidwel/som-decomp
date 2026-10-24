.setcpu "65816"
.segment "CODE"
.org $B4E0
map_control_0fb4e0:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
