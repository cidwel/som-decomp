.setcpu "65816"
.segment "CODE"
.org $0447
map_control_0e0447:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
