.setcpu "65816"
.segment "CODE"
.org $8C28
map_control_0c8c28:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
