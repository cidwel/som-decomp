.setcpu "65816"
.segment "CODE"
.org $1E24
map_control_0c1e24:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
