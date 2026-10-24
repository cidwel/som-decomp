.setcpu "65816"
.segment "CODE"
.org $6A03
map_control_0f6a03:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
