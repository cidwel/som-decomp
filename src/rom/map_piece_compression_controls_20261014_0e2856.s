.setcpu "65816"
.segment "CODE"
.org $2856
map_control_0e2856:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
