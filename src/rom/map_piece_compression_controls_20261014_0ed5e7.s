.setcpu "65816"
.segment "CODE"
.org $D5E7
map_control_0ed5e7:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
