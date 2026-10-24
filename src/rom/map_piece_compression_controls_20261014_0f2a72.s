.setcpu "65816"
.segment "CODE"
.org $2A72
map_control_0f2a72:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
