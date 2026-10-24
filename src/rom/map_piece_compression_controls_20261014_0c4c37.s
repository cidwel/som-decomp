.setcpu "65816"
.segment "CODE"
.org $4C37
map_control_0c4c37:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
