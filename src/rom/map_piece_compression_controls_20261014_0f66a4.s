.setcpu "65816"
.segment "CODE"
.org $66A4
map_control_0f66a4:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
