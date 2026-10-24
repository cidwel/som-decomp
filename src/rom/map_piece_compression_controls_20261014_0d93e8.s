.setcpu "65816"
.segment "CODE"
.org $93E8
map_control_0d93e8:
    .byte $E7 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
