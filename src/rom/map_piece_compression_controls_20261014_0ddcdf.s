.setcpu "65816"
.segment "CODE"
.org $DCDF
map_control_0ddcdf:
    .byte $E7 ; previous-row copy count
