.setcpu "65816"
.segment "CODE"
.org $5D1A
map_control_0c5d1a:
    .byte $C3 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
