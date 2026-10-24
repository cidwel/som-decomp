.setcpu "65816"
.segment "CODE"
.org $4506
map_control_0c4506:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
