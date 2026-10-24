.setcpu "65816"
.segment "CODE"
.org $116A
map_control_0c116a:
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
