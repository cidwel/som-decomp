.setcpu "65816"
.segment "CODE"
.org $C492
map_control_0fc492:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
