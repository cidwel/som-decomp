.setcpu "65816"
.segment "CODE"
.org $105B
map_control_0c105b:
    .byte $D1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
