.setcpu "65816"
.segment "CODE"
.org $5AA9
map_control_0d5aa9:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
