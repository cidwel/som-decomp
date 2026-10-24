.setcpu "65816"
.segment "CODE"
.org $6800
map_control_0c6800:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
