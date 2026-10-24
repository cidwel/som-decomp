.setcpu "65816"
.segment "CODE"
.org $6EED
map_control_0e6eed:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
