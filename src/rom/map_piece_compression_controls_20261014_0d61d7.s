.setcpu "65816"
.segment "CODE"
.org $61D7
map_control_0d61d7:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
