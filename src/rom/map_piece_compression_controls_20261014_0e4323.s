.setcpu "65816"
.segment "CODE"
.org $4323
map_control_0e4323:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
