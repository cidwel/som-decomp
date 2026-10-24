.setcpu "65816"
.segment "CODE"
.org $32D2
map_control_0f32d2:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
