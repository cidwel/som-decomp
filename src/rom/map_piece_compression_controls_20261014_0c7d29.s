.setcpu "65816"
.segment "CODE"
.org $7D29
map_control_0c7d29:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
