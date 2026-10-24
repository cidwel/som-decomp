.setcpu "65816"
.segment "CODE"
.org $75C4
map_control_0d75c4:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
