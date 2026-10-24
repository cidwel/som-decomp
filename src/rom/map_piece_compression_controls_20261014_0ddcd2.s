.setcpu "65816"
.segment "CODE"
.org $DCD2
map_control_0ddcd2:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
