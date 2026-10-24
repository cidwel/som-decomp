.setcpu "65816"
.segment "CODE"
.org $7F05
map_control_0d7f05:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
