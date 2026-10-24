.setcpu "65816"
.segment "CODE"
.org $5D70
map_control_0d5d70:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
