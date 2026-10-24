.setcpu "65816"
.segment "CODE"
.org $4E24
map_control_0d4e24:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E3 ; previous-row copy count
