.setcpu "65816"
.segment "CODE"
.org $ED42
map_control_0eed42:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
