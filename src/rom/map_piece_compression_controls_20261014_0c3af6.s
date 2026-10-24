.setcpu "65816"
.segment "CODE"
.org $3AF6
map_control_0c3af6:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
