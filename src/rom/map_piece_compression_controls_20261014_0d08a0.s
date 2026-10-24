.setcpu "65816"
.segment "CODE"
.org $08A0
map_control_0d08a0:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $E1 ; previous-row copy count
