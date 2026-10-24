.setcpu "65816"
.segment "CODE"
.org $5421
map_control_0d5421:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
