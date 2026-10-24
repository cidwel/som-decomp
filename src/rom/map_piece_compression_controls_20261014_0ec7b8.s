.setcpu "65816"
.segment "CODE"
.org $C7B8
map_control_0ec7b8:
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
