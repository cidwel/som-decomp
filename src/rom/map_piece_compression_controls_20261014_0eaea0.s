.setcpu "65816"
.segment "CODE"
.org $AEA0
map_control_0eaea0:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
