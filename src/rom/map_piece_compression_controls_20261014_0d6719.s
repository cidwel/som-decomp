.setcpu "65816"
.segment "CODE"
.org $6719
map_control_0d6719:
    .byte $D1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
