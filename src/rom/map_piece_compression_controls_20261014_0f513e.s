.setcpu "65816"
.segment "CODE"
.org $513E
map_control_0f513e:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
