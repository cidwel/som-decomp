.setcpu "65816"
.segment "CODE"
.org $9AB7
map_control_0e9ab7:
    .byte $E0 ; previous-row copy escape
    .byte $AD ; row-distance/count
