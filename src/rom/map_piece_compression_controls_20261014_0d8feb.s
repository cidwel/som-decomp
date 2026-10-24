.setcpu "65816"
.segment "CODE"
.org $8FEB
map_control_0d8feb:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
