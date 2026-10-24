.setcpu "65816"
.segment "CODE"
.org $7029
map_control_0c7029:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
