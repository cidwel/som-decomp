.setcpu "65816"
.segment "CODE"
.org $0C84
map_control_0e0c84:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
