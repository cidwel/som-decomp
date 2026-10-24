.setcpu "65816"
.segment "CODE"
.org $29D3
map_control_0f29d3:
    .byte $C2 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
