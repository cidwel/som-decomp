.setcpu "65816"
.segment "CODE"
.org $1969
map_control_0d1969:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
