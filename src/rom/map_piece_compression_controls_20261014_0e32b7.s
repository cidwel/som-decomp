.setcpu "65816"
.segment "CODE"
.org $32B7
map_control_0e32b7:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
