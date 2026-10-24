.setcpu "65816"
.segment "CODE"
.org $2B11
map_control_0d2b11:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
