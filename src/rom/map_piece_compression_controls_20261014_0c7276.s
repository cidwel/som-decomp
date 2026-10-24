.setcpu "65816"
.segment "CODE"
.org $7276
map_control_0c7276:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
