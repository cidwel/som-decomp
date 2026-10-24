.setcpu "65816"
.segment "CODE"
.org $0BAF
map_control_0e0baf:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
