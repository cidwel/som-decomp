.setcpu "65816"
.segment "CODE"
.org $AA9C
map_control_0eaa9c:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E1 ; previous-row copy count
