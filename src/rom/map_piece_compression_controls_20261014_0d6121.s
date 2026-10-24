.setcpu "65816"
.segment "CODE"
.org $6121
map_control_0d6121:
    .byte $E0 ; previous-row copy escape
    .byte $AE ; row-distance/count
