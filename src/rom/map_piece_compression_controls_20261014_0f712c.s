.setcpu "65816"
.segment "CODE"
.org $712C
map_control_0f712c:
    .byte $C9 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
