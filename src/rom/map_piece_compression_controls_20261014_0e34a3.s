.setcpu "65816"
.segment "CODE"
.org $34A3
map_control_0e34a3:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
