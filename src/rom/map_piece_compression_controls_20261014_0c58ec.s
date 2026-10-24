.setcpu "65816"
.segment "CODE"
.org $58EC
map_control_0c58ec:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
