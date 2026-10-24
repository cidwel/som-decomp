.setcpu "65816"
.segment "CODE"
.org $6097
map_control_0d6097:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
