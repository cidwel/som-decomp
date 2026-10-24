.setcpu "65816"
.segment "CODE"
.org $59B0
map_control_0f59b0:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
