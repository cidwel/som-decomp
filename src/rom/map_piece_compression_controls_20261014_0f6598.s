.setcpu "65816"
.segment "CODE"
.org $6598
map_control_0f6598:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
