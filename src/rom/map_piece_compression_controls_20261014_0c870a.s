.setcpu "65816"
.segment "CODE"
.org $870A
map_control_0c870a:
    .byte $EE ; backreference distance high bits
    .byte $92 ; distance low bit/count
    .byte $CF ; same-value copy count/distance
