.setcpu "65816"
.segment "CODE"
.org $FC28
map_control_0dfc28:
    .byte $E3 ; previous-row copy count
