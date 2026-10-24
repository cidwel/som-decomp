.setcpu "65816"
.segment "CODE"
.org $3D5B
map_control_0f3d5b:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C5 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
