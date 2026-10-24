.setcpu "65816"
.segment "CODE"
.org $885D
map_control_0c885d:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
