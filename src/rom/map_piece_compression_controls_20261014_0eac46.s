.setcpu "65816"
.segment "CODE"
.org $AC46
map_control_0eac46:
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
