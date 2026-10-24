.setcpu "65816"
.segment "CODE"
.org $893F
map_control_0c893f:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
