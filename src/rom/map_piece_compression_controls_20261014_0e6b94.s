.setcpu "65816"
.segment "CODE"
.org $6B94
map_control_0e6b94:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
