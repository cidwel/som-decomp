.setcpu "65816"
.segment "CODE"
.org $56B1
map_control_0c56b1:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
