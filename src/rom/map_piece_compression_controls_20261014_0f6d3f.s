.setcpu "65816"
.segment "CODE"
.org $6D3F
map_control_0f6d3f:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
