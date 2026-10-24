.setcpu "65816"
.segment "CODE"
.org $D011
map_control_0ed011:
    .byte $E3 ; previous-row copy count
