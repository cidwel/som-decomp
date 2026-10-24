.setcpu "65816"
.segment "CODE"
.org $808D
map_control_0f808d:
    .byte $E5 ; previous-row copy count
