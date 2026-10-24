.setcpu "65816"
.segment "CODE"
.org $715A
map_control_0d715a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
