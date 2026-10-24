.setcpu "65816"
.segment "CODE"
.org $661C
map_control_0d661c:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
