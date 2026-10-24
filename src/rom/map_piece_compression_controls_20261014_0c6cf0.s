.setcpu "65816"
.segment "CODE"
.org $6CF0
map_control_0c6cf0:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
