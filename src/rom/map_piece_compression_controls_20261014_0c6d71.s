.setcpu "65816"
.segment "CODE"
.org $6D71
map_control_0c6d71:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
