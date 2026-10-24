.setcpu "65816"
.segment "CODE"
.org $9AD5
map_control_0f9ad5:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
