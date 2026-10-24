.setcpu "65816"
.segment "CODE"
.org $CCB5
map_control_0eccb5:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
