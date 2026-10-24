.setcpu "65816"
.segment "CODE"
.org $7B97
map_control_0c7b97:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
