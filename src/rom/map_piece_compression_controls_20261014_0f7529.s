.setcpu "65816"
.segment "CODE"
.org $7529
map_control_0f7529:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
