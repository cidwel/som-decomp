.setcpu "65816"
.segment "CODE"
.org $8447
map_control_0e8447:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
