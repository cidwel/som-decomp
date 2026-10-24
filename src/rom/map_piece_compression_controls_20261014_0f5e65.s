.setcpu "65816"
.segment "CODE"
.org $5E65
map_control_0f5e65:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
