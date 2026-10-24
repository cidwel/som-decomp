.setcpu "65816"
.segment "CODE"
.org $375D
map_control_0d375d:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
