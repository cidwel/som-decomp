.setcpu "65816"
.segment "CODE"
.org $1EF9
map_control_0f1ef9:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
