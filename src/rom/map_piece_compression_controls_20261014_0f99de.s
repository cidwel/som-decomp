.setcpu "65816"
.segment "CODE"
.org $99DE
map_control_0f99de:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
