.setcpu "65816"
.segment "CODE"
.org $5F00
map_control_0d5f00:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
