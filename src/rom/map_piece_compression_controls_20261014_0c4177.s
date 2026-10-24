.setcpu "65816"
.segment "CODE"
.org $4177
map_control_0c4177:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
