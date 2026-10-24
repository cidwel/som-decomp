.setcpu "65816"
.segment "CODE"
.org $9C3E
map_control_0e9c3e:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
