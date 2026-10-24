.setcpu "65816"
.segment "CODE"
.org $846A
map_control_0f846a:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
