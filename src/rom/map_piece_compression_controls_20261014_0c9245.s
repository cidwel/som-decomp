.setcpu "65816"
.segment "CODE"
.org $9245
map_control_0c9245:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
