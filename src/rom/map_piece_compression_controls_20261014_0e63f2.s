.setcpu "65816"
.segment "CODE"
.org $63F2
map_control_0e63f2:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
