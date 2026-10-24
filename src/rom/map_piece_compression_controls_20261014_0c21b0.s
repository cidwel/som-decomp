.setcpu "65816"
.segment "CODE"
.org $21B0
map_control_0c21b0:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
