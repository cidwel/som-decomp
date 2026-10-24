.setcpu "65816"
.segment "CODE"
.org $5F9B
map_control_0e5f9b:
    .byte $E0 ; previous-row copy escape
    .byte $40 ; row-distance/count
