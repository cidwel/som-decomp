.setcpu "65816"
.segment "CODE"
.org $2007
map_control_0f2007:
    .byte $E5 ; previous-row copy count
