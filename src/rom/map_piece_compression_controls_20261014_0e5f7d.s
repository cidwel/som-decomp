.setcpu "65816"
.segment "CODE"
.org $5F7D
map_control_0e5f7d:
    .byte $E0 ; previous-row copy escape
    .byte $40 ; row-distance/count
