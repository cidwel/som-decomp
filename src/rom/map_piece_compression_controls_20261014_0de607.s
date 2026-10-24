.setcpu "65816"
.segment "CODE"
.org $E607
map_control_0de607:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
