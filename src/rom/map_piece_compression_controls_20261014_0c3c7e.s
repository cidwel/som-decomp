.setcpu "65816"
.segment "CODE"
.org $3C7E
map_control_0c3c7e:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
