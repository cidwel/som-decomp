.setcpu "65816"
.segment "CODE"
.org $18F9
map_control_0c18f9:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
