.setcpu "65816"
.segment "CODE"
.org $77E5
map_control_0f77e5:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
    .byte $E7 ; previous-row copy count
