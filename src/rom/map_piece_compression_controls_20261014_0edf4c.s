.setcpu "65816"
.segment "CODE"
.org $DF4C
map_control_0edf4c:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
