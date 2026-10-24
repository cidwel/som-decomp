.setcpu "65816"
.segment "CODE"
.org $9221
map_control_0d9221:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
