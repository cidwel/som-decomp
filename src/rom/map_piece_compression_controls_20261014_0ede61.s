.setcpu "65816"
.segment "CODE"
.org $DE61
map_control_0ede61:
    .byte $E1 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
