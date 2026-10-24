.setcpu "65816"
.segment "CODE"
.org $40E7
map_control_0e40e7:
    .byte $C9 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E5 ; previous-row copy count
