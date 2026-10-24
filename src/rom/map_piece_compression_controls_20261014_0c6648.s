.setcpu "65816"
.segment "CODE"
.org $6648
map_control_0c6648:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
