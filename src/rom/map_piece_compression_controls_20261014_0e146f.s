.setcpu "65816"
.segment "CODE"
.org $146F
map_control_0e146f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
