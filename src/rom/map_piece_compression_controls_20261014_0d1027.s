.setcpu "65816"
.segment "CODE"
.org $1027
map_control_0d1027:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
