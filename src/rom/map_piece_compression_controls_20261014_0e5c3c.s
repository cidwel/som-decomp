.setcpu "65816"
.segment "CODE"
.org $5C3C
map_control_0e5c3c:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
