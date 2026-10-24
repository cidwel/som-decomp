.setcpu "65816"
.segment "CODE"
.org $7F86
map_control_0f7f86:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
