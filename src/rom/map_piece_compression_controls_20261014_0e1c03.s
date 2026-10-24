.setcpu "65816"
.segment "CODE"
.org $1C03
map_control_0e1c03:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
