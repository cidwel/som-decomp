.setcpu "65816"
.segment "CODE"
.org $AC3E
map_control_0eac3e:
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
