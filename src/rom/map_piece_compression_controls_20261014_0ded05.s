.setcpu "65816"
.segment "CODE"
.org $ED05
map_control_0ded05:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
    .byte $E3 ; previous-row copy count
