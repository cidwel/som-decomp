.setcpu "65816"
.segment "CODE"
.org $D46B
map_control_0ed46b:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
