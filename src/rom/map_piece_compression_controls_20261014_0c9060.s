.setcpu "65816"
.segment "CODE"
.org $9060
map_control_0c9060:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
