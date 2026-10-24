.setcpu "65816"
.segment "CODE"
.org $548C
map_control_0f548c:
    .byte $C4 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
