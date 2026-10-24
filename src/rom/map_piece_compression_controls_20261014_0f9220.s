.setcpu "65816"
.segment "CODE"
.org $9220
map_control_0f9220:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
