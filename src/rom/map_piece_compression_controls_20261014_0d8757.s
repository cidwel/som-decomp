.setcpu "65816"
.segment "CODE"
.org $8757
map_control_0d8757:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $CC ; same-value copy count/distance
