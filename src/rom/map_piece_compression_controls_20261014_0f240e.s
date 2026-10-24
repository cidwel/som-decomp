.setcpu "65816"
.segment "CODE"
.org $240E
map_control_0f240e:
    .byte $E1 ; previous-row copy count
