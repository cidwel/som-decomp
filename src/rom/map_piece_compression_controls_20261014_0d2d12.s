.setcpu "65816"
.segment "CODE"
.org $2D12
map_control_0d2d12:
    .byte $C9 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
