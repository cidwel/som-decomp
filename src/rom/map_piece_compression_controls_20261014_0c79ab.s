.setcpu "65816"
.segment "CODE"
.org $79AB
map_control_0c79ab:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
