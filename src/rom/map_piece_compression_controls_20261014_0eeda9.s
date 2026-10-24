.setcpu "65816"
.segment "CODE"
.org $EDA9
map_control_0eeda9:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
