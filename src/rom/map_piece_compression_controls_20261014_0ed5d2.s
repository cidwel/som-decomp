.setcpu "65816"
.segment "CODE"
.org $D5D2
map_control_0ed5d2:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
