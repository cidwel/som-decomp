.setcpu "65816"
.segment "CODE"
.org $3E0A
map_control_0d3e0a:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
