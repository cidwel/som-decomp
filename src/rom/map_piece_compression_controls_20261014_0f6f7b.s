.setcpu "65816"
.segment "CODE"
.org $6F7B
map_control_0f6f7b:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
