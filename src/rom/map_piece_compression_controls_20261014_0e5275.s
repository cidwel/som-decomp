.setcpu "65816"
.segment "CODE"
.org $5275
map_control_0e5275:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
