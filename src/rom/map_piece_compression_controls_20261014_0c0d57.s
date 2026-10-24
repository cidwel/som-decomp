.setcpu "65816"
.segment "CODE"
.org $0D57
map_control_0c0d57:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
