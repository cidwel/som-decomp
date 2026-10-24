.setcpu "65816"
.segment "CODE"
.org $64ED
map_control_0c64ed:
    .byte $E1 ; previous-row copy count
