.setcpu "65816"
.segment "CODE"
.org $14C2
map_control_0e14c2:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
