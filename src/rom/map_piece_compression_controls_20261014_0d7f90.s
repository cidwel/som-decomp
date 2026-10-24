.setcpu "65816"
.segment "CODE"
.org $7F90
map_control_0d7f90:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
