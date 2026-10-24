.setcpu "65816"
.segment "CODE"
.org $CD39
map_control_0dcd39:
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
