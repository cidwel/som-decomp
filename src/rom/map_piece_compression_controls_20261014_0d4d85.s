.setcpu "65816"
.segment "CODE"
.org $4D85
map_control_0d4d85:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
