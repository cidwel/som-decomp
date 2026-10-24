.setcpu "65816"
.segment "CODE"
.org $B601
map_control_0db601:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
