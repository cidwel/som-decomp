.setcpu "65816"
.segment "CODE"
.org $5539
map_control_0e5539:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
