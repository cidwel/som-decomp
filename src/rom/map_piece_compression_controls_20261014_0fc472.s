.setcpu "65816"
.segment "CODE"
.org $C472
map_control_0fc472:
    .byte $EA ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
    .byte $D5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
