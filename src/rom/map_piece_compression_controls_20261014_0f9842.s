.setcpu "65816"
.segment "CODE"
.org $9842
map_control_0f9842:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
