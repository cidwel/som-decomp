.setcpu "65816"
.segment "CODE"
.org $32E5
map_control_0f32e5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
