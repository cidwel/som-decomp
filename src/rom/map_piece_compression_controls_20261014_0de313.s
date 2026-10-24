.setcpu "65816"
.segment "CODE"
.org $E313
map_control_0de313:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
