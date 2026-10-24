.setcpu "65816"
.segment "CODE"
.org $5A88
map_control_0e5a88:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
