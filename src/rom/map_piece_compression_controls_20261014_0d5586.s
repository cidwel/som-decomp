.setcpu "65816"
.segment "CODE"
.org $5586
map_control_0d5586:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
