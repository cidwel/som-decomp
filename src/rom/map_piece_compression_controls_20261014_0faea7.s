.setcpu "65816"
.segment "CODE"
.org $AEA7
map_control_0faea7:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
