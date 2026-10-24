.setcpu "65816"
.segment "CODE"
.org $3792
map_control_0d3792:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $E1 ; previous-row copy count
