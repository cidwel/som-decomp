.setcpu "65816"
.segment "CODE"
.org $7F5E
map_control_0e7f5e:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
