.setcpu "65816"
.segment "CODE"
.org $6288
map_control_0d6288:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
