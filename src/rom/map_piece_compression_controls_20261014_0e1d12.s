.setcpu "65816"
.segment "CODE"
.org $1D12
map_control_0e1d12:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
