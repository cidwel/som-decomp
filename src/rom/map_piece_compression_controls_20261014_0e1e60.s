.setcpu "65816"
.segment "CODE"
.org $1E60
map_control_0e1e60:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
