.setcpu "65816"
.segment "CODE"
.org $41CF
map_control_0c41cf:
    .byte $CD ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
