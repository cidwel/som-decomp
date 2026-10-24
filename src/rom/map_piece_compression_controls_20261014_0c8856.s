.setcpu "65816"
.segment "CODE"
.org $8856
map_control_0c8856:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
