.setcpu "65816"
.segment "CODE"
.org $6699
map_control_0d6699:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
