.setcpu "65816"
.segment "CODE"
.org $1E9A
map_control_0f1e9a:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
