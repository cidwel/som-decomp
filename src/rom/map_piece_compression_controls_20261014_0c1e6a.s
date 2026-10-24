.setcpu "65816"
.segment "CODE"
.org $1E6A
map_control_0c1e6a:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
