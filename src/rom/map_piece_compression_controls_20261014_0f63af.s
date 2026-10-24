.setcpu "65816"
.segment "CODE"
.org $63AF
map_control_0f63af:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
