.setcpu "65816"
.segment "CODE"
.org $B09A
map_control_0db09a:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
