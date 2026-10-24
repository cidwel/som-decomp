.setcpu "65816"
.segment "CODE"
.org $879E
map_control_0d879e:
    .byte $E0 ; previous-row copy escape
    .byte $D3 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
