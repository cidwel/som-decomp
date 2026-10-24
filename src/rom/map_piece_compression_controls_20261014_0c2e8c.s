.setcpu "65816"
.segment "CODE"
.org $2E8C
map_control_0c2e8c:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
