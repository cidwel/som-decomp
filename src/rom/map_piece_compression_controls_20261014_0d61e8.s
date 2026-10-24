.setcpu "65816"
.segment "CODE"
.org $61E8
map_control_0d61e8:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
