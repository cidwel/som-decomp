.setcpu "65816"
.segment "CODE"
.org $1EBC
map_control_0c1ebc:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
