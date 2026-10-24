.setcpu "65816"
.segment "CODE"
.org $2199
map_control_0d2199:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
