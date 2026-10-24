.setcpu "65816"
.segment "CODE"
.org $7645
map_control_0c7645:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
