.setcpu "65816"
.segment "CODE"
.org $4A33
map_control_0c4a33:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
