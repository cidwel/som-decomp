.setcpu "65816"
.segment "CODE"
.org $8FB8
map_control_0c8fb8:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
