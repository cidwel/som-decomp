.setcpu "65816"
.segment "CODE"
.org $0F64
map_control_0d0f64:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
