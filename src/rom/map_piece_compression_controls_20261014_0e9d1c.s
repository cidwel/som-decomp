.setcpu "65816"
.segment "CODE"
.org $9D1C
map_control_0e9d1c:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
