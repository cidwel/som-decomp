.setcpu "65816"
.segment "CODE"
.org $1AF6
map_control_0f1af6:
    .byte $E0 ; previous-row copy escape
    .byte $C8 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
