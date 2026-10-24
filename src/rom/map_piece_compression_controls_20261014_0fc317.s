.setcpu "65816"
.segment "CODE"
.org $C317
map_control_0fc317:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
