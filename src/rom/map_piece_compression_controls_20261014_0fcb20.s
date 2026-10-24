.setcpu "65816"
.segment "CODE"
.org $CB20
map_control_0fcb20:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
