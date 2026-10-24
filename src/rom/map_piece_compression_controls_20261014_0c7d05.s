.setcpu "65816"
.segment "CODE"
.org $7D05
map_control_0c7d05:
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
