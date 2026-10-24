.setcpu "65816"
.segment "CODE"
.org $0C45
map_control_0c0c45:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
