.setcpu "65816"
.segment "CODE"
.org $13F8
map_control_0e13f8:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
