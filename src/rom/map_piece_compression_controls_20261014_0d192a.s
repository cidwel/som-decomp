.setcpu "65816"
.segment "CODE"
.org $192A
map_control_0d192a:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
