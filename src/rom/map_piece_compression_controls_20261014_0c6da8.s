.setcpu "65816"
.segment "CODE"
.org $6DA8
map_control_0c6da8:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
