.setcpu "65816"
.segment "CODE"
.org $8481
map_control_0e8481:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
