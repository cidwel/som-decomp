.setcpu "65816"
.segment "CODE"
.org $5312
map_control_0c5312:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
