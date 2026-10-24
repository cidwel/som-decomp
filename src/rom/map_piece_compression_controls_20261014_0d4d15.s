.setcpu "65816"
.segment "CODE"
.org $4D15
map_control_0d4d15:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
