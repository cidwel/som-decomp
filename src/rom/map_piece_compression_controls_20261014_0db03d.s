.setcpu "65816"
.segment "CODE"
.org $B03D
map_control_0db03d:
    .byte $E2 ; previous-row copy count
