.setcpu "65816"
.segment "CODE"
.org $14FD
map_control_0c14fd:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
