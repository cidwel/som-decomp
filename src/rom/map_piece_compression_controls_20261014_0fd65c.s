.setcpu "65816"
.segment "CODE"
.org $D65C
map_control_0fd65c:
    .byte $E5 ; previous-row copy count
