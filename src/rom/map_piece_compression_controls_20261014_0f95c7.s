.setcpu "65816"
.segment "CODE"
.org $95C7
map_control_0f95c7:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $6B ; distance low bit/count
