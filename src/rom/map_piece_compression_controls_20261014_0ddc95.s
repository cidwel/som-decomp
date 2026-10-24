.setcpu "65816"
.segment "CODE"
.org $DC95
map_control_0ddc95:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
