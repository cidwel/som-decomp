.setcpu "65816"
.segment "CODE"
.org $5F39
map_control_0c5f39:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
