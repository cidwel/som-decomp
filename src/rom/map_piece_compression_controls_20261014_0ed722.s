.setcpu "65816"
.segment "CODE"
.org $D722
map_control_0ed722:
    .byte $EB ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
