.setcpu "65816"
.segment "CODE"
.org $8550
map_control_0e8550:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
