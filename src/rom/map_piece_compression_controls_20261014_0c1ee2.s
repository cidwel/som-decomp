.setcpu "65816"
.segment "CODE"
.org $1EE2
map_control_0c1ee2:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
