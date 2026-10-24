.setcpu "65816"
.segment "CODE"
.org $D805
map_control_0ed805:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
