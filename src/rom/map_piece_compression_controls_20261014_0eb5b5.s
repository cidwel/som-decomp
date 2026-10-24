.setcpu "65816"
.segment "CODE"
.org $B5B5
map_control_0eb5b5:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
