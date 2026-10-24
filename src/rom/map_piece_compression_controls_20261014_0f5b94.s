.setcpu "65816"
.segment "CODE"
.org $5B94
map_control_0f5b94:
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
