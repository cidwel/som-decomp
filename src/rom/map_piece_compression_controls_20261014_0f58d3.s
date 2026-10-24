.setcpu "65816"
.segment "CODE"
.org $58D3
map_control_0f58d3:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
