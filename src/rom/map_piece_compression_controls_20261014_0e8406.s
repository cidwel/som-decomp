.setcpu "65816"
.segment "CODE"
.org $8406
map_control_0e8406:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
