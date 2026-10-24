.setcpu "65816"
.segment "CODE"
.org $589C
map_control_0f589c:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E1 ; previous-row copy count
