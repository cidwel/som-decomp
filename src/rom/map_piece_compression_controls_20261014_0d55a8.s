.setcpu "65816"
.segment "CODE"
.org $55A8
map_control_0d55a8:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
