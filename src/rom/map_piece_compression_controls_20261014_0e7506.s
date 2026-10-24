.setcpu "65816"
.segment "CODE"
.org $7506
map_control_0e7506:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E2 ; previous-row copy count
