.setcpu "65816"
.segment "CODE"
.org $AE22
map_control_0eae22:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
