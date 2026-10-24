.setcpu "65816"
.segment "CODE"
.org $8BE1
map_control_0c8be1:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
