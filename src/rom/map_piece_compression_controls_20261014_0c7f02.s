.setcpu "65816"
.segment "CODE"
.org $7F02
map_control_0c7f02:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
