.setcpu "65816"
.segment "CODE"
.org $FC1B
map_control_0ffc1b:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
