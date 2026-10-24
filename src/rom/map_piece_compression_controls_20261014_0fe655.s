.setcpu "65816"
.segment "CODE"
.org $E655
map_control_0fe655:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
