.setcpu "65816"
.segment "CODE"
.org $629E
map_control_0d629e:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
