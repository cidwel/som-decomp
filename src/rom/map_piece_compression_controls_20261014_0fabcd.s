.setcpu "65816"
.segment "CODE"
.org $ABCD
map_control_0fabcd:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
