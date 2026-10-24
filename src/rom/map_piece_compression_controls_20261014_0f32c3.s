.setcpu "65816"
.segment "CODE"
.org $32C3
map_control_0f32c3:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
