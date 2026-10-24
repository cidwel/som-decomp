.setcpu "65816"
.segment "CODE"
.org $0FA3
map_control_0f0fa3:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
