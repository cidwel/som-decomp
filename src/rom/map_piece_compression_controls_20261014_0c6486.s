.setcpu "65816"
.segment "CODE"
.org $6486
map_control_0c6486:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
