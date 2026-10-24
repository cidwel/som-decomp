.setcpu "65816"
.segment "CODE"
.org $3489
map_control_0c3489:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
