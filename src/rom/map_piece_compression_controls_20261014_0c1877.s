.setcpu "65816"
.segment "CODE"
.org $1877
map_control_0c1877:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
