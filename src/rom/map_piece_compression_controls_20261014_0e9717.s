.setcpu "65816"
.segment "CODE"
.org $9717
map_control_0e9717:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
