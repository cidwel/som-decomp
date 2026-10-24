.setcpu "65816"
.segment "CODE"
.org $73D0
map_control_0c73d0:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
