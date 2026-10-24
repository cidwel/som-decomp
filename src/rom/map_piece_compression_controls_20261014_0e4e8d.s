.setcpu "65816"
.segment "CODE"
.org $4E8D
map_control_0e4e8d:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
