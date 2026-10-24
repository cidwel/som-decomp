.setcpu "65816"
.segment "CODE"
.org $60FD
map_control_0c60fd:
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
