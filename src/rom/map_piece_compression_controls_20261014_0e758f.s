.setcpu "65816"
.segment "CODE"
.org $758F
map_control_0e758f:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
