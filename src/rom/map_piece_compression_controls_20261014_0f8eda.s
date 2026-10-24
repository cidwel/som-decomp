.setcpu "65816"
.segment "CODE"
.org $8EDA
map_control_0f8eda:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
