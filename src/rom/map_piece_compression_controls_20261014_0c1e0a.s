.setcpu "65816"
.segment "CODE"
.org $1E0A
map_control_0c1e0a:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
