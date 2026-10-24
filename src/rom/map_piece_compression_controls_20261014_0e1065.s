.setcpu "65816"
.segment "CODE"
.org $1065
map_control_0e1065:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
