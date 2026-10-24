.setcpu "65816"
.segment "CODE"
.org $FCDF
map_control_0dfcdf:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
