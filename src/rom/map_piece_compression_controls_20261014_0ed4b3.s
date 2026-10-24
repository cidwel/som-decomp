.setcpu "65816"
.segment "CODE"
.org $D4B3
map_control_0ed4b3:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
