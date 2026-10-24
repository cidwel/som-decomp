.setcpu "65816"
.segment "CODE"
.org $45C4
map_control_0e45c4:
    .byte $F2 ; progressive-copy count
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
