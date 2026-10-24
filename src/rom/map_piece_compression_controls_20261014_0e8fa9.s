.setcpu "65816"
.segment "CODE"
.org $8FA9
map_control_0e8fa9:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
