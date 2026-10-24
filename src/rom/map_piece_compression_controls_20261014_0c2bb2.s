.setcpu "65816"
.segment "CODE"
.org $2BB2
map_control_0c2bb2:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
