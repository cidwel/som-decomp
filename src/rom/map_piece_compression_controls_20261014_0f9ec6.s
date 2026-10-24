.setcpu "65816"
.segment "CODE"
.org $9EC6
map_control_0f9ec6:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
