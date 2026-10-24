.setcpu "65816"
.segment "CODE"
.org $11E7
map_control_0c11e7:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
