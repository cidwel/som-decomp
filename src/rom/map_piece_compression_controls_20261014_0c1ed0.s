.setcpu "65816"
.segment "CODE"
.org $1ED0
map_control_0c1ed0:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
