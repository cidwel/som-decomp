.setcpu "65816"
.segment "CODE"
.org $DF52
map_control_0edf52:
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
