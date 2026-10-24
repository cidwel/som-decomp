.setcpu "65816"
.segment "CODE"
.org $75B3
map_control_0c75b3:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
