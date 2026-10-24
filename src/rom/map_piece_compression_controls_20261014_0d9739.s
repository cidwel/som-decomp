.setcpu "65816"
.segment "CODE"
.org $9739
map_control_0d9739:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
