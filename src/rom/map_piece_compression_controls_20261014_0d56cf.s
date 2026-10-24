.setcpu "65816"
.segment "CODE"
.org $56CF
map_control_0d56cf:
    .byte $CB ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
