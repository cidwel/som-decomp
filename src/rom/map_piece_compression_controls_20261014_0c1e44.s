.setcpu "65816"
.segment "CODE"
.org $1E44
map_control_0c1e44:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
