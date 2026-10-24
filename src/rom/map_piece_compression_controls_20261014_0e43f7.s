.setcpu "65816"
.segment "CODE"
.org $43F7
map_control_0e43f7:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
