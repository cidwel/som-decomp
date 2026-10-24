.setcpu "65816"
.segment "CODE"
.org $1070
map_control_0d1070:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
