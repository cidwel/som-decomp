.setcpu "65816"
.segment "CODE"
.org $D986
map_control_0dd986:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
