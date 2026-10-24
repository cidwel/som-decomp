.setcpu "65816"
.segment "CODE"
.org $1C6D
map_control_0e1c6d:
    .byte $E1 ; previous-row copy count
    .byte $D4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
