.setcpu "65816"
.segment "CODE"
.org $3014
map_control_0c3014:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
