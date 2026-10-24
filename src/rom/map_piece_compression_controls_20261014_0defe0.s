.setcpu "65816"
.segment "CODE"
.org $EFE0
map_control_0defe0:
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
