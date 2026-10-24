.setcpu "65816"
.segment "CODE"
.org $E71D
map_control_0fe71d:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
