.setcpu "65816"
.segment "CODE"
.org $2E11
map_control_0f2e11:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E2 ; previous-row copy count
