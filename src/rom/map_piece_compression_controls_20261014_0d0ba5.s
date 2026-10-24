.setcpu "65816"
.segment "CODE"
.org $0BA5
map_control_0d0ba5:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
