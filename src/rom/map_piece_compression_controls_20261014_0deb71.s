.setcpu "65816"
.segment "CODE"
.org $EB71
map_control_0deb71:
    .byte $C7 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
