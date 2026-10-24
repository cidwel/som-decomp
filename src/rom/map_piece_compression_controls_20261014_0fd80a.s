.setcpu "65816"
.segment "CODE"
.org $D80A
map_control_0fd80a:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
