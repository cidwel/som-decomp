.setcpu "65816"
.segment "CODE"
.org $D980
map_control_0fd980:
    .byte $E2 ; previous-row copy count
