.setcpu "65816"
.segment "CODE"
.org $8D87
map_control_0f8d87:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
