.setcpu "65816"
.segment "CODE"
.org $8CCD
map_control_0f8ccd:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
