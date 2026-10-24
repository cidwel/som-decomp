.setcpu "65816"
.segment "CODE"
.org $29E1
map_control_0e29e1:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $CB ; same-value copy count/distance
