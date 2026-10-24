.setcpu "65816"
.segment "CODE"
.org $2EC8
map_control_0f2ec8:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
