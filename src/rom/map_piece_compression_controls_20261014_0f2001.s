.setcpu "65816"
.segment "CODE"
.org $2001
map_control_0f2001:
    .byte $E5 ; previous-row copy count
