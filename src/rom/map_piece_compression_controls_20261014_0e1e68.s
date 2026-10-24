.setcpu "65816"
.segment "CODE"
.org $1E68
map_control_0e1e68:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
