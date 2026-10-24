.setcpu "65816"
.segment "CODE"
.org $05BA
map_control_0f05ba:
    .byte $E3 ; previous-row copy count
