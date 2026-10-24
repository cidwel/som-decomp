.setcpu "65816"
.segment "CODE"
.org $34A9
map_control_0c34a9:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
