.setcpu "65816"
.segment "CODE"
.org $6107
map_control_0d6107:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
