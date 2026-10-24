.setcpu "65816"
.segment "CODE"
.org $4587
map_control_0d4587:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
