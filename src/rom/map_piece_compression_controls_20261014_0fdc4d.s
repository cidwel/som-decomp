.setcpu "65816"
.segment "CODE"
.org $DC4D
map_control_0fdc4d:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E2 ; previous-row copy count
