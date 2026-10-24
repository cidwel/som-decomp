.setcpu "65816"
.segment "CODE"
.org $1DA3
map_control_0e1da3:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
