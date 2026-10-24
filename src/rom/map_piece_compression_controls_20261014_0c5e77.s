.setcpu "65816"
.segment "CODE"
.org $5E77
map_control_0c5e77:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
