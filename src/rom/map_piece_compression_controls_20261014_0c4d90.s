.setcpu "65816"
.segment "CODE"
.org $4D90
map_control_0c4d90:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
