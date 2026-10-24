.setcpu "65816"
.segment "CODE"
.org $9071
map_control_0c9071:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
