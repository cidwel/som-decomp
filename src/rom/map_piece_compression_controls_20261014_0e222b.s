.setcpu "65816"
.segment "CODE"
.org $222B
map_control_0e222b:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
