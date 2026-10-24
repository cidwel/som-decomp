.setcpu "65816"
.segment "CODE"
.org $5490
map_control_0e5490:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
