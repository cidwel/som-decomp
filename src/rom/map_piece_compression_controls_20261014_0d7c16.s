.setcpu "65816"
.segment "CODE"
.org $7C16
map_control_0d7c16:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
