.setcpu "65816"
.segment "CODE"
.org $45B9
map_control_0f45b9:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
