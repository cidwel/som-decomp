.setcpu "65816"
.segment "CODE"
.org $7FA6
map_control_0f7fa6:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
