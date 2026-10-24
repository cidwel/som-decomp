.setcpu "65816"
.segment "CODE"
.org $876B
map_control_0d876b:
    .byte $D2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
