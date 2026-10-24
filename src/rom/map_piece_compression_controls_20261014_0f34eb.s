.setcpu "65816"
.segment "CODE"
.org $34EB
map_control_0f34eb:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
