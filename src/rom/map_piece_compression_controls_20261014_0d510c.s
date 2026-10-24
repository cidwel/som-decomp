.setcpu "65816"
.segment "CODE"
.org $510C
map_control_0d510c:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $CF ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
