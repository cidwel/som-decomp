.setcpu "65816"
.segment "CODE"
.org $C8DC
map_control_0fc8dc:
    .byte $D4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
