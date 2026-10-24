.setcpu "65816"
.segment "CODE"
.org $5F76
map_control_0c5f76:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
