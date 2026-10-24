.setcpu "65816"
.segment "CODE"
.org $106B
map_control_0e106b:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C3 ; same-value copy count/distance
