.setcpu "65816"
.segment "CODE"
.org $D574
map_control_0ed574:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
