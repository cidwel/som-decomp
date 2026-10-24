.setcpu "65816"
.segment "CODE"
.org $4FD9
map_control_0f4fd9:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
