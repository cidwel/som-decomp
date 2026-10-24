.setcpu "65816"
.segment "CODE"
.org $1C48
map_control_0e1c48:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C9 ; same-value copy count/distance
