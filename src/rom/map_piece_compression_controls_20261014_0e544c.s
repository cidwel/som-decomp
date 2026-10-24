.setcpu "65816"
.segment "CODE"
.org $544C
map_control_0e544c:
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
