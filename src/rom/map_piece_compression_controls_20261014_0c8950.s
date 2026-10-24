.setcpu "65816"
.segment "CODE"
.org $8950
map_control_0c8950:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
