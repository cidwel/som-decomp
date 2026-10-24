.setcpu "65816"
.segment "CODE"
.org $18B7
map_control_0c18b7:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
