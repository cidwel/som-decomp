.setcpu "65816"
.segment "CODE"
.org $820D
map_control_0c820d:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
