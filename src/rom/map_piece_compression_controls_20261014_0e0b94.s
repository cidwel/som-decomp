.setcpu "65816"
.segment "CODE"
.org $0B94
map_control_0e0b94:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
