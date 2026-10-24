.setcpu "65816"
.segment "CODE"
.org $4DE0
map_control_0c4de0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
