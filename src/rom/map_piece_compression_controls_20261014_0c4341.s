.setcpu "65816"
.segment "CODE"
.org $4341
map_control_0c4341:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
