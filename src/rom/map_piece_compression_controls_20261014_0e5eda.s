.setcpu "65816"
.segment "CODE"
.org $5EDA
map_control_0e5eda:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
