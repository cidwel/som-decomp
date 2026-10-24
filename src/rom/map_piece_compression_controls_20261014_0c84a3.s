.setcpu "65816"
.segment "CODE"
.org $84A3
map_control_0c84a3:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
