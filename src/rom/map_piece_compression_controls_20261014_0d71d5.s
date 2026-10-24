.setcpu "65816"
.segment "CODE"
.org $71D5
map_control_0d71d5:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
