.setcpu "65816"
.segment "CODE"
.org $83B5
map_control_0d83b5:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
