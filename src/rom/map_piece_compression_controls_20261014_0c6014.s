.setcpu "65816"
.segment "CODE"
.org $6014
map_control_0c6014:
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
