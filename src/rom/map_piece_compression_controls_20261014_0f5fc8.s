.setcpu "65816"
.segment "CODE"
.org $5FC8
map_control_0f5fc8:
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
