.setcpu "65816"
.segment "CODE"
.org $5DBB
map_control_0e5dbb:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
