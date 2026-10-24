.setcpu "65816"
.segment "CODE"
.org $1205
map_control_0c1205:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
