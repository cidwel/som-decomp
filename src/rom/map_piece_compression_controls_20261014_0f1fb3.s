.setcpu "65816"
.segment "CODE"
.org $1FB3
map_control_0f1fb3:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
