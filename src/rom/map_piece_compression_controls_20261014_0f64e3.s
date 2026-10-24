.setcpu "65816"
.segment "CODE"
.org $64E3
map_control_0f64e3:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $92 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E5 ; previous-row copy count
