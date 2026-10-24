.setcpu "65816"
.segment "CODE"
.org $7F50
map_control_0c7f50:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
