.setcpu "65816"
.segment "CODE"
.org $8538
map_control_0e8538:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
