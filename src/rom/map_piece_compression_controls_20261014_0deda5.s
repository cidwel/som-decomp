.setcpu "65816"
.segment "CODE"
.org $EDA5
map_control_0deda5:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
