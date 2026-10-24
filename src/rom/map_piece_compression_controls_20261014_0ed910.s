.setcpu "65816"
.segment "CODE"
.org $D910
map_control_0ed910:
    .byte $E2 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
