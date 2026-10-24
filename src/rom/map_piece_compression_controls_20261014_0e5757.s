.setcpu "65816"
.segment "CODE"
.org $5757
map_control_0e5757:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
