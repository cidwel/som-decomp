.setcpu "65816"
.segment "CODE"
.org $5616
map_control_0d5616:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
