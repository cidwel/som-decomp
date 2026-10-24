.setcpu "65816"
.segment "CODE"
.org $56E8
map_control_0f56e8:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
