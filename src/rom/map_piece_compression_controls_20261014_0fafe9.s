.setcpu "65816"
.segment "CODE"
.org $AFE9
map_control_0fafe9:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
