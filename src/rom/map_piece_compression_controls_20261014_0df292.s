.setcpu "65816"
.segment "CODE"
.org $F292
map_control_0df292:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
