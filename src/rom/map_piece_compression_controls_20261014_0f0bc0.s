.setcpu "65816"
.segment "CODE"
.org $0BC0
map_control_0f0bc0:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
