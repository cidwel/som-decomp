.setcpu "65816"
.segment "CODE"
.org $80C5
map_control_0d80c5:
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
