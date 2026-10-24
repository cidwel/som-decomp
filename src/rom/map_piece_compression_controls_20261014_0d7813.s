.setcpu "65816"
.segment "CODE"
.org $7813
map_control_0d7813:
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
