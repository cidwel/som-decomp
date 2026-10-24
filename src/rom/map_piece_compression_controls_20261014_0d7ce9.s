.setcpu "65816"
.segment "CODE"
.org $7CE9
map_control_0d7ce9:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
