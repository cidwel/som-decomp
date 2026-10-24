.setcpu "65816"
.segment "CODE"
.org $D4CA
map_control_0ed4ca:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
