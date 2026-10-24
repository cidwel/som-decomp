.setcpu "65816"
.segment "CODE"
.org $57DD
map_control_0d57dd:
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
