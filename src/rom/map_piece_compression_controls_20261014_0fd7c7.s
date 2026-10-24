.setcpu "65816"
.segment "CODE"
.org $D7C7
map_control_0fd7c7:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
