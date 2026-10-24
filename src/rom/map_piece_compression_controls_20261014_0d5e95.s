.setcpu "65816"
.segment "CODE"
.org $5E95
map_control_0d5e95:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
