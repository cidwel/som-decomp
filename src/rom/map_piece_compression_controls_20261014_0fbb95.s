.setcpu "65816"
.segment "CODE"
.org $BB95
map_control_0fbb95:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
