.setcpu "65816"
.segment "CODE"
.org $3521
map_control_0e3521:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
