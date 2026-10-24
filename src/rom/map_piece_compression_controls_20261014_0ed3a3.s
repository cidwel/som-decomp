.setcpu "65816"
.segment "CODE"
.org $D3A3
map_control_0ed3a3:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
