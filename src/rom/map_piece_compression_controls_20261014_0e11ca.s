.setcpu "65816"
.segment "CODE"
.org $11CA
map_control_0e11ca:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
