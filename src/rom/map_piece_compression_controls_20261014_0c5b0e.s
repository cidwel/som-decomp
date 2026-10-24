.setcpu "65816"
.segment "CODE"
.org $5B0E
map_control_0c5b0e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
