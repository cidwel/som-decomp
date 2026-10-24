.setcpu "65816"
.segment "CODE"
.org $83B8
map_control_0d83b8:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
