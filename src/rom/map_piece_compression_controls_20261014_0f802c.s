.setcpu "65816"
.segment "CODE"
.org $802C
map_control_0f802c:
    .byte $E1 ; previous-row copy count
