.setcpu "65816"
.segment "CODE"
.org $E513
map_control_0fe513:
    .byte $C5 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E5 ; previous-row copy count
