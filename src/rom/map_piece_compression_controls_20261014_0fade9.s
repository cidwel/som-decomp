.setcpu "65816"
.segment "CODE"
.org $ADE9
map_control_0fade9:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
