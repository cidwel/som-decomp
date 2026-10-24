.setcpu "65816"
.segment "CODE"
.org $6C40
map_control_0c6c40:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
