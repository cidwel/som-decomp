.setcpu "65816"
.segment "CODE"
.org $16B5
map_control_0c16b5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $66 ; distance low bit/count
