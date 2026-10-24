.setcpu "65816"
.segment "CODE"
.org $75AD
map_control_0f75ad:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
