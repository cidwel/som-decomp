.setcpu "65816"
.segment "CODE"
.org $7086
map_control_0e7086:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
