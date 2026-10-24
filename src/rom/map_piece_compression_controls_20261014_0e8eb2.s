.setcpu "65816"
.segment "CODE"
.org $8EB2
map_control_0e8eb2:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
