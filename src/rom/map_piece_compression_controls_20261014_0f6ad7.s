.setcpu "65816"
.segment "CODE"
.org $6AD7
map_control_0f6ad7:
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
