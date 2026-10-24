.setcpu "65816"
.segment "CODE"
.org $5E96
map_control_0c5e96:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
