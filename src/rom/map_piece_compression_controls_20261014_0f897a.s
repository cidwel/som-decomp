.setcpu "65816"
.segment "CODE"
.org $897A
map_control_0f897a:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
