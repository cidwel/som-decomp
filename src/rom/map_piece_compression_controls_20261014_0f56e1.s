.setcpu "65816"
.segment "CODE"
.org $56E1
map_control_0f56e1:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
