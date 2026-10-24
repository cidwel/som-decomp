.setcpu "65816"
.segment "CODE"
.org $7526
map_control_0d7526:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $3F ; distance low bit/count
