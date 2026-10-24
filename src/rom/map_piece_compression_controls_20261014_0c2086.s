.setcpu "65816"
.segment "CODE"
.org $2086
map_control_0c2086:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
