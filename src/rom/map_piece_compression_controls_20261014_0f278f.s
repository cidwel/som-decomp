.setcpu "65816"
.segment "CODE"
.org $278F
map_control_0f278f:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $CE ; same-value copy count/distance
