.setcpu "65816"
.segment "CODE"
.org $EE77
map_control_0dee77:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
