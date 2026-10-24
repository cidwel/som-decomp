.setcpu "65816"
.segment "CODE"
.org $15E9
map_control_0d15e9:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
