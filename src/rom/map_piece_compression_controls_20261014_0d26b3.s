.setcpu "65816"
.segment "CODE"
.org $26B3
map_control_0d26b3:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
