.setcpu "65816"
.segment "CODE"
.org $35BF
map_control_0d35bf:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
