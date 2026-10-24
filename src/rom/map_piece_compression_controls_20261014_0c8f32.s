.setcpu "65816"
.segment "CODE"
.org $8F32
map_control_0c8f32:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
