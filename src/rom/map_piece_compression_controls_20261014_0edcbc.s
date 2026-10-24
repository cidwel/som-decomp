.setcpu "65816"
.segment "CODE"
.org $DCBC
map_control_0edcbc:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $C2 ; same-value copy count/distance
