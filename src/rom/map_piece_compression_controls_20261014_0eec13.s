.setcpu "65816"
.segment "CODE"
.org $EC13
map_control_0eec13:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
