.setcpu "65816"
.segment "CODE"
.org $1539
map_control_0f1539:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
