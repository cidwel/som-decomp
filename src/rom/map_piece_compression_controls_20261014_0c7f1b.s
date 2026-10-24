.setcpu "65816"
.segment "CODE"
.org $7F1B
map_control_0c7f1b:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
