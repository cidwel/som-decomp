.setcpu "65816"
.segment "CODE"
.org $531D
map_control_0c531d:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
