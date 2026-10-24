.setcpu "65816"
.segment "CODE"
.org $1976
map_control_0d1976:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
