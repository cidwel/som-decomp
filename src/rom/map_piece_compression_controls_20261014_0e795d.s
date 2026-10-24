.setcpu "65816"
.segment "CODE"
.org $795D
map_control_0e795d:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $D1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
